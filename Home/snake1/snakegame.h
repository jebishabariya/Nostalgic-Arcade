#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include <QWidget>
#include <QMainWindow>
#include <QKeyEvent>
#include <QTimer>
#include <QImage>
#include <Qvector>
#include <QRect>

class SnakeGame : public QMainWindow {
    Q_OBJECT

public:
    SnakeGame(QWidget *parent = nullptr);
    ~SnakeGame();

protected:
    void paintEvent(QPaintEvent *event) override;
    void timerEvent(QTimerEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    void initGame();
    void doDrawing();
    void checkCollision();
    void move();
    void locateApple();
    void initObstacles();
    std::vector<QRect> obstacles;

    static const int B_WIDTH = 1000;
    static const int B_HEIGHT = 700;
    static const int DOT_SIZE = 10;
    static const int ALL_DOTS = 900;
    static const int RAND_POS = 50;
    static const int DELAY = 150;

    int timerId;
    int dots;
    int apple_x;
    int apple_y;
    int score;

    int x[ALL_DOTS];
    int y[ALL_DOTS];

    bool leftDirection;
    bool rightDirection;
    bool upDirection;
    bool downDirection;
    bool inGame;

    //std::vector<QPoint> obstacles;

    QImage head;
    QImage dot;
    QImage apple;
    QImage obstacle;
};

#endif // SNAKEGAME_H
