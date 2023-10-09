#ifndef STARTMENU_H
#define STARTMENU_H
#include "pin.h"
#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class StartMenu; }
QT_END_NAMESPACE

class StartMenu : public QMainWindow
{
    Q_OBJECT

public:
    StartMenu(QWidget *parent = nullptr);
    ~StartMenu();

private slots:
    void readCard();

private:
    Ui::StartMenu *ui;
    QSerialPort *serial;
    Pin *pin;

};

#endif // STARTMENU_H
