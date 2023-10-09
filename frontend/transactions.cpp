#include "transactions.h"
#include "mainmenu.h"
#include "ui_transactions.h"
#include "mysingleton.h"

Transactions::Transactions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Transactions)
{
    ui->setupUi(this);

    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getTransactions(QNetworkReply*)));
    reply = getManager->get(request);
}

Transactions::~Transactions()
{
    delete ui;
}

void Transactions::getTransactions(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    // Get amount
    QString Amount;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        Amount += "-" + QString::number(json_obj["amount"].toInt())+ "€" + "\n";
    }
    ui->TransactionsLabelAmount->setText(Amount);

    //Get timestamp
    QString TimeStamp;
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        QString timestamp = json_obj["timeStamp"].toString().left(10);
        TimeStamp += timestamp + "\n";
    }
    ui->TransactionsLabelTimeStamp->setText(TimeStamp);

    reply->deleteLater();
    getManager->deleteLater();

}

void Transactions::on_TransactionsReturnButton_clicked()
{
    MainMenu *mainMenu = new MainMenu();
    this->hide();
    mainMenu->show();

}
