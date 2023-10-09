#include "withdraw.h"
#include "mainmenu.h"
#include "mysingleton.h"
#include "ui_withdraw.h"

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QDebug>


Withdraw::Withdraw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Withdraw)
{
    ui->setupUi(this);
}

Withdraw::~Withdraw()
{
    delete ui;
}
// 20 Eur button
void Withdraw::on_Eur20Button_clicked()
{
    QJsonObject jsonObj;
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    jsonObj.insert("amount", "20");

    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEurSlot(QNetworkReply)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

    ui->labelOutput->setText("20€ Otto suoritettu");
    qDebug()<< "20 Eur clicked";
}

// 40 Eur button
void Withdraw::on_Eur40Button_clicked()
{
    QJsonObject jsonObj;
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    jsonObj.insert("amount", "40");

    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEurSlot(QNetworkReply)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

    ui->labelOutput->setText("40€ Otto suoritettu");
    qDebug()<< "40 Eur clicked";
}

// 60 Eur button
void Withdraw::on_Eur60Button_clicked()
{
    QJsonObject jsonObj;
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    jsonObj.insert("amount", "60");

    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEurSlot(QNetworkReply)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

    ui->labelOutput->setText("60€ Otto suoritettu");
    qDebug()<< "60 Eur clicked";
}

// 100 Eur button
void Withdraw::on_Eur100Button_clicked()
{
    QJsonObject jsonObj;
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    jsonObj.insert("amount", "100");

    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEurSlot(QNetworkReply)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

    ui->labelOutput->setText("100€ Otto suoritettu");
    qDebug()<< "100 Eur clicked";
}

// 200 Eur button
void Withdraw::on_Eur200Button_clicked()
{
    QJsonObject jsonObj;
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    jsonObj.insert("amount", "200");

    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEurSlot(QNetworkReply)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

    ui->labelOutput->setText("200€ Otto suoritettu");
    qDebug()<< "200Eur clicked";
}

// 500 Eur button
void Withdraw::on_Eur500Button_clicked()
{
    QJsonObject jsonObj;
    MySingleton *objectSingleton = MySingleton::getInstance();
    QString accountId = objectSingleton->getAccountId();
    jsonObj.insert("amount", "500");

    QString site_url="http://localhost:3000/transaction/" + accountId;
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEurSlot(QNetworkReply)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());

    ui->labelOutput->setText("500€ Otto suoritettu");
    qDebug()<< "500 Eur clicked";
}

// Slot
void Withdraw::addEurSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}

// Return Button
void Withdraw::on_WithdrawReturnButton_clicked()
{
    MainMenu *mainMenu = new MainMenu();

    this->hide();
    mainMenu->show();
}
