#include "mainwindow.h"

#include <QApplication>
#include<iostream>
//Initialze variable;
bool snakeGame; //to check if game is running or not
const int width=50;//walls
const int height = 50;//walls
int x,y; // position variables
int fruitX. fruitY; // position variables for fruits
int score;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
