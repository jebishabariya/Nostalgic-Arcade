#include "mainwindowpingpong.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowPingPong w;
    w.show();
    return a.exec();
}

