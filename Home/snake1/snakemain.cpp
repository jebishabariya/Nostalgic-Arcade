#include <QApplication>
#include <QWidget>
#include "snakegame.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    SnakeGame w;
    w.show();
    return a.exec();
}
