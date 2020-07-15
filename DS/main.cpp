#include "park.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Park w;
    w.show();
    return a.exec();
}
