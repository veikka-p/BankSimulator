#ifndef WITHDRAW_H
#define WITHDRAW_H

#include "QtWidgets/qdialog.h"
#include <QDialog>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Withdraw;
}

class Withdraw : public QDialog
{
    Q_OBJECT

public:
    explicit Withdraw(QWidget *parent = nullptr);
    ~Withdraw();
private slots:
    //void on_WithdrawReturnButton_clicked();

    void on_Eur20Button_clicked();
    void on_Eur40Button_clicked();
    void on_Eur60Button_clicked();
    void on_Eur100Button_clicked();
    void on_Eur200Button_clicked();
    void on_Eur500Button_clicked();

    void addEurSlot(QNetworkReply *reply);
    void on_WithdrawReturnButton_clicked();
private:
    Ui::Withdraw *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // WITHDRAW_H
