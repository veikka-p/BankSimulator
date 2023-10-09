#ifndef CARDSELECT_H
#define CARDSELECT_H

#include <QDialog>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class CardSelect;


}

class CardSelect : public QDialog
{
    Q_OBJECT

public:
    explicit CardSelect(QString value, QDialog *parent = nullptr);
    ~CardSelect();
    void setAccountId(const QString &newAccountId);
    QString userId;
    QString accountId;

private slots:
    void on_CreditButton_clicked();
    void on_DebitButton_clicked();
    void getAccountInfo (QNetworkReply *reply);

private:
    Ui::CardSelect *ui;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // CARDSELECT_H


