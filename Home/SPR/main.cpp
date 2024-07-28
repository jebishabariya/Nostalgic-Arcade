#include "scissorsmainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowScissors w;
    w.show();
    return a.exec();
}
