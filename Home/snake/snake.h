#ifndef SNAKE_H
#define SNAKE_H

#include <QList>
#include <QPoint>

enum class Direction { Up, Down, Left, Right };

class Snake
{
public:
    Snake();
    void init();
    void setDirection(Direction dir);
    void move();
    void grow();
    QList<QPoint>& getBody();
    QPoint head();
    bool checkCollision();
    bool checkSelfCollision();
    Direction getcurrentDirection();

private:
    QList<QPoint> body;
    Direction direction;
};

#endif // SNAKE_H
