#ifndef LOGOUT_H
#define LOGOUT_H
#include <QDialog>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class LogOut;
}

class LogOut : public QDialog
{
    Q_OBJECT

public:
    explicit LogOut(QWidget *parent = nullptr);
    ~LogOut();

private:
    Ui::LogOut *ui;

};

#endif // LOGOUT_H


