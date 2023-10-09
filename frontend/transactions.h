#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>


namespace Ui {
class Transactions;
}

class Transactions : public QDialog
{
    Q_OBJECT

public:
    explicit Transactions(QWidget *parent = nullptr);
    ~Transactions();

private slots:
    void getTransactions (QNetworkReply *reply);
    void on_TransactionsReturnButton_clicked();

private:
    Ui::Transactions *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // TRANSACTIONS_H
