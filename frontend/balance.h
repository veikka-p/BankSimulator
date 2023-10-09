#ifndef BALANCE_H
#define BALANCE_H

#include <QDialog>

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Balance;
}

class Balance : public QDialog
{
    Q_OBJECT

public:
    explicit Balance(QWidget *parent = nullptr);
    ~Balance();
    void setBalance(const QString &newBalance);
    QString QBalance;
    QString accountId;

private slots:
    void on_BalanceReturnButton_clicked();
    void getBalanceInfo (QNetworkReply *reply);
    void getBalance();

private:
    Ui::Balance *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // BALANCE_H
