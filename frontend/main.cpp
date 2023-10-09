#include "startmenu.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Pin w("05009BA4AA");
    w.show();
    return a.exec();
}
