#ifndef PIN_H
#define PIN_H

#include "qtimer.h"
#include <QDialog>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class Pin; }
QT_END_NAMESPACE

class Pin : public QDialog
{
    Q_OBJECT

public:
    explicit Pin(QString value, QDialog *parent = nullptr);
    ~Pin();
    void setLoggedIn(bool value); // Lisätty setLoggedIn-metodi
    void setCardNumber(const QString &newCardNumber);
    void setUserId(const QString &newUserId);

public slots:
    void closeWindow();
    void checkLineEdit();
    void startAutoTimer();

private slots:
    void handleButton();
    void startTimer();
    void handleTimeout();
    void stopTimer();

    void getUserInfo (QNetworkReply *reply);
private:
    Ui::Pin *ui;
    int timerId;
    int attempts;
    QTimer timer;
    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString pinCode;
    QString userId;
    QString cardNumber;

protected:
    void timerEvent(QTimerEvent *event) override;

signals:
    void timerEnded();
};

#endif // PIN_H
