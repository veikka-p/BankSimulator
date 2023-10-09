#include "balance.h"
#include "ui_balance.h"
#include "mainmenu.h"
#include "mysingleton.h"

Balance::Balance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Balance)
{
    ui->setupUi(this);
    getBalance();

}

Balance::~Balance()
{
    delete ui;
}

void Balance::getBalance()
{
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    QString site_url="http://localhost:3000/account/" + accountId;
    qDebug()<<"Balance accountId " + accountId;
    QNetworkRequest request((site_url));
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getBalanceInfo(QNetworkReply*)));
    reply = getManager->get(request);
}

void Balance::getBalanceInfo(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString Balance = QString::number(json_obj["balance"].toInt());
    ui->BalanceLabel->setText(Balance + "€");
    reply->deleteLater();
    getManager->deleteLater();
}
void Balance::setBalance(const QString &newBalance)
{
    QBalance = newBalance;
}


void Balance::on_BalanceReturnButton_clicked()
{
    MainMenu *mainMenu = new MainMenu();
    this->hide();
    mainMenu->show();
}
