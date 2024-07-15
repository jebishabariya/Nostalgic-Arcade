#include "snake.h"
#include <QDebug>

Snake::Snake()
{
    direction = Direction::Right; // Initial direction
}

void Snake::init()
{
    body.clear();
    body << QPoint(5, 5) << QPoint(5, 6) << QPoint(5, 7); // Initial Snake length
}

void Snake::setDirection(Direction dir)
{
    direction = dir;
}

void Snake::move()
{
    for (int i = body.size() - 1; i > 0; --i) {//movement of all the body of snake
      body[i] = body[i - 1];
    }

    switch (direction) {
    case Direction::Up:
            body.first().ry()--;
        break;
    case Direction::Down:
            body.first().ry()++;
        break;
    case Direction::Left:
            body.first().rx()--;
        break;
    case Direction::Right:
            body.first().rx()++;
        break;
    default:
        break;
    }
}
Direction Snake :: getcurrentDirection(){
    return direction;
}

void Snake::grow()
{
    body.append(body.last());
}

QList<QPoint>& Snake::getBody()
{
    return body;
}

QPoint Snake::head()
{
    return body.first();
}

bool Snake::checkCollision()
{
    QPoint head = body.first();
    return head.x() < 0 || head.x() >= 60 || head.y() < 0 || head.y() >= 40; // Adjust boundaries as needed
}

bool Snake::checkSelfCollision()
{
    QPoint head = body.first();
    for (int i = 1; i < body.size(); ++i) {
        if (head == body.at(i)) {
            return true;
        }
    }
    return false;
}
