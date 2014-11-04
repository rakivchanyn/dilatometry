#include "dilatometryhelper.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DilatometryHelper w;
    w.show();

    return a.exec();
}
