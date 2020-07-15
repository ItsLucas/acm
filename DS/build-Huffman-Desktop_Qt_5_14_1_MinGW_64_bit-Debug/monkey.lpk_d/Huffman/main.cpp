#include "huffmanwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HuffmanWindow w;
    w.show();
    return a.exec();
}
