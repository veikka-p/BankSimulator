#include "mainmenu.h"
#include "logout.h"
#include "transactions.h"
#include "ui_mainmenu.h"
#include "balance.h"
#include "withdraw.h"

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_BalanceButton_clicked()
{

    Balance *balance = new Balance();
    this->hide();
    balance->show();
}


void MainMenu::on_TransactionsButton_clicked()
{
    Transactions *transactions = new Transactions();
    this->hide();
    transactions->show();
}


void MainMenu::on_WithdrawButton_clicked()
{
    Withdraw *withdraw = new Withdraw();
    this->hide();
    withdraw->show();
}


void MainMenu::on_LogOutButton_clicked()
{
    LogOut *logout = new LogOut();
    this->hide();
    logout->show();
}
