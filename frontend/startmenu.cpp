#include "startmenu.h"
#include "ui_startmenu.h"
#include "pin.h"

StartMenu::StartMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartMenu)
    , pin(nullptr) // Initialize pin to nullptr
{
    ui->setupUi(this);

    // Initialize serial
    serial = new QSerialPort(this);
    serial->setPortName("com3");
    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setFlowControl(QSerialPort::HardwareControl);
    serial->setStopBits(QSerialPort::OneStop);
    serial->open(QIODevice::ReadOnly);

    // Connect signals and slots
    connect(serial, SIGNAL(readyRead()), this, SLOT(readCard()));
}

StartMenu::~StartMenu()
{
    delete ui;
}

void StartMenu::readCard()
{
    QByteArray data = serial->read(25); // Read 12 bytes (the length of a card number)
    QString cardNumber = QString(data).mid(3, 10); // Extract the card number (skip the '\n-' at the beginning)

    // Delete previous pin instance if it exists
    if (pin != nullptr) {
        pin->close(); // Close the existing pin window
        delete pin; // Delete the existing pin instance
        pin = nullptr; // Set pin to nullptr
    }

    // Show new pin instance only if it doesn't exist
    if (pin == nullptr) {
        pin = new Pin(cardNumber);
        pin->show();
    }

    this->hide();
}

