QT       += core gui
QT       += serialport
QT +=network


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balance.cpp \
    cardselect.cpp \
    logout.cpp \
    main.cpp \
    mainmenu.cpp \
    mysingleton.cpp \
    pin.cpp \
    startmenu.cpp \
    transactions.cpp \
    withdraw.cpp

HEADERS += \
    balance.h \
    cardselect.h \
    logout.h \
    mainmenu.h \
    mysingleton.h \
    pin.h \
    startmenu.h \
    transactions.h \
    withdraw.h

FORMS += \
    balance.ui \
    cardselect.ui \
    logout.ui \
    mainmenu.ui \
    pin.ui \
    startmenu.ui \
    transactions.ui \
    withdraw.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
