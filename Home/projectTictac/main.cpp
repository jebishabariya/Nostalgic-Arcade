#include "mainwindowtictactoe.h"
#include "ui_mainwindowtictactoe.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowTicTacToe w;
    w.show();
    return a.exec();
}
