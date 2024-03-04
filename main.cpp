#include "xcolors.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    XColors w;
    w.show();

    return a.exec();
}
