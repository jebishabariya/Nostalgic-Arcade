#ifndef SNAKEMAIN_H
#define SNAKEMAIN_H
#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include "gameboard.h"

class snakemain : public QMainWindow
{
    Q_OBJECT
public:
    snakemain(QWidget *parent = nullptr);
    ~snakemain();
protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    GameBoard *gameBoard;
    QTimer *gameTimer;
public:
    void startGame();
    void stopGame();
};

#endif // SNAKEMAIN_H
