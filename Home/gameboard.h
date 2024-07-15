#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>

class GameBoard : public QWidget
{
    Q_OBJECT
public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();
    void keyPressEvent(QKeyEvent *event);
    void paintEvent(QPaintEvent *event);

public slots:
    void updateGame();

private:
    enum Direction { None, Up, Down, Left, Right };

    static const int BoardWidth = 20;
    static const int BoardHeight = 20;
    static const int SquareSize = 20;

    QPoint snake[BoardWidth * BoardHeight];
    int snakeLength;
    QPoint food;

    Direction currentDirection;
    bool gameOver;
};

#endif // GAMEBOARD_H
