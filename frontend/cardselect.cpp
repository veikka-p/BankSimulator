#include "cardselect.h"
#include "mainmenu.h"
#include "mysingleton.h"
#include "ui_cardselect.h"
#include <QDialog>

CardSelect::CardSelect(QString value, QDialog *parent) :
    QDialog(parent),
    ui(new Ui::CardSelect)
{
    ui->setupUi(this);
    userId = value;
    QString site_url="http://localhost:3000/account/user/" +userId;
    QNetworkRequest request((site_url));
    getManager = new QNetworkAccessManager(this);
    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getAccountInfo(QNetworkReply*)));
    reply = getManager->get(request);
}

void CardSelect::getAccountInfo(QNetworkReply *reply)
{
    QByteArray response_data = reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    QString accountId = QString::number(json_obj["account_id"].toInt());
    MySingleton *objectSingleton = MySingleton::getInstance();
    objectSingleton->setAccountId(accountId);
    reply->deleteLater();
    getManager->deleteLater();
}

void CardSelect::setAccountId(const QString &newAccountId)
{
    accountId = newAccountId;
}

CardSelect::~CardSelect()
{
    delete ui;
}

void CardSelect::on_CreditButton_clicked()
{
    MainMenu *mainMenu = new MainMenu();
    mainMenu->show();
    this->close();
}


void CardSelect::on_DebitButton_clicked()
{
    MainMenu *mainMenu = new MainMenu();
    mainMenu->show();
    this->close();
}

