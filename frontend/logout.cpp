#include "startmenu.h"
#include "logout.h"
#include <QTimer>
#include "ui_logout.h"

LogOut::LogOut(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogOut)
{
    ui->setupUi(this);

    this->setWindowModality(Qt::WindowModal);

    QTimer::singleShot(5000, this, [=](){

        StartMenu *startMenu = new StartMenu();
        this->hide();
        startMenu->show();

    });
}

LogOut::~LogOut()
{
    delete ui;
}
