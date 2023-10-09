#ifndef MAINMENU_H
#define MAINMENU_H

#include <QDialog>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_BalanceButton_clicked();
    void on_TransactionsButton_clicked();
    void on_WithdrawButton_clicked();
    void on_LogOutButton_clicked();

private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
