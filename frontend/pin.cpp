#include "startmenu.h"
#include "cardselect.h"
#include "pin.h"
#include "ui_pin.h"
#include "QTimer"
#include "QThread"
#include <QDebug>
#include <QApplication>

Pin::Pin(QString value, QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::Pin)
    , timerId(-1) // initialize timer
    , timer(this) // initialize timerId to -1
{
    ui->setupUi(this); // set up UI
    ui->ProgressBar->setTextVisible(false);
    ui->ProgressBar->setVisible(false);
    ui->InputPinLabel->setText("Enter PIN:");
    cardNumber = value;

    // connect button and line edit to their respective slots
    connect(ui->EnterPinButton, &QPushButton::clicked, this, &Pin::handleButton);
    connect(ui->InsertPinLineEdit, &QLineEdit::textChanged, this, &Pin::startAutoTimer);

    // connect timer to slot that will be called when the timer times out
    connect(&timer, &QTimer::timeout, this, &Pin::handleTimeout);
    timer.start(100); // start timer

    // connect signal to close window
    connect(this, &Pin::timerEnded,this, &Pin::close);

    // Get Pincode
    QString site_url="http://localhost:3000/bankCard/" + cardNumber;
    QNetworkRequest request((site_url));

    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getUserInfo(QNetworkReply*)));
    reply = getManager->get(request);
}

void Pin::getUserInfo(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    pinCode = json_obj["pinCode"].toString();
    qDebug()<<"Pin " + pinCode;
    userId = QString::number(json_obj["user_id"].toInt());
    reply->deleteLater();
    getManager->deleteLater();
}


void Pin::setCardNumber(const QString &newCardNumber)
{
    cardNumber = newCardNumber;
}

void Pin::setUserId(const QString &newUserId)
{
    userId = newUserId;
}



void Pin::checkLineEdit()
{
    if (ui->InsertPinLineEdit->text().isEmpty())
    {
        startTimer();
    }
}

void Pin::startTimer()
{
    ui->ProgressBar->setValue(0);
    ui->ProgressBar->setVisible(false);
    stopTimer(); // stop timer if it's already running
   // timerId = startTimer(100); // start timer and store the timerId
}

void Pin::startAutoTimer()
{
    if (ui->InsertPinLineEdit->text().isEmpty())
    {
        startTimer();
    }
}

void Pin::stopTimer()
{
    if (timerId != -1) {
        killTimer(timerId); // stop timer using timerId
        timerId = -1;
    }
}

void Pin::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == timerId) { // check if event is from timer
        handleTimeout();
    } else {
        QWidget::timerEvent(event);
    }
}

void Pin::handleTimeout()
{
    int value = ui->ProgressBar->value();
    if (value >= 1000) {
        stopTimer();
        if (ui->InsertPinLineEdit->text().isEmpty()){
            emit timerEnded();
            // close window if no PIN has been entered
        }
        return;
    }
    ui->ProgressBar->setValue(value + 1);
}

void Pin::closeWindow()
{
    close(); // close the window
}

void Pin::handleButton()
{
    QString pin = ui->InsertPinLineEdit->text();
    static int attempts = 3; // number of attempts remaining
    if (pin.isEmpty()) {
        if (timerId == -1){
            startTimer(); // start timer if PIN is empty
        }
    } else if (pin == pinCode) {
        ui->InputPinLabel->setText("PIN oikein");
        //if (timerId != -1) {
            stopTimer(); // stop timer if PIN is correct
        CardSelect *cardSelect = new CardSelect(userId);
            cardSelect->show(); // show the new window
            this->close();

    } else {
        attempts--;
        if (attempts == 0) {
            ui->PinAttemptsLabel->setText("No more attempts, closing!");
            StartMenu *startMenu = new StartMenu();
            startMenu->show();
            this->close(); // close current window
        } else {
            ui->PinAttemptsLabel->setText(QString("Yrityksiä: %1").arg(attempts));
            if (timerId == -1){
                startTimer();
            } else {
                ui->InputPinLabel->setText(QString("PIN väärin"));
            }
        }
    }
}

Pin::~Pin()
{
    delete ui;
}


