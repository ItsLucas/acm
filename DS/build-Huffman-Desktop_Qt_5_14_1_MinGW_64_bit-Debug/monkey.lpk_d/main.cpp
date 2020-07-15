#include "monkeygui.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MonkeyGUI w;
    w.show();
    return a.exec();
}
