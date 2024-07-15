#include "snakemain.h"
#include "gameboard.h"
snakemain::snakemain(QWidget *parent): QMainWindow(parent)
{
    gameBoard = new GameBoard(this);
    setCentralWidget(gameBoard);

    gameTimer = new QTimer(this);
    connect(gameTimer, SIGNAL(timeout()), gameBoard, SLOT(updateGame()));
    gameTimer->start(100); // Adjust speed as needed
}
snakemain::~snakemain(){
    delete gameTimer;
}
void snakemain::keyPressEvent(QKeyEvent *event){
    gameBoard->keyPressEvent(event);
}
void snakemain::startGame(){
    gameTimer->start(100);
}
void snakemain::stopGame()
{
    gameTimer->stop(); // Stop the game timer
}
