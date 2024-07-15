#ifndef FOOD_H
#define FOOD_H

#include <QPoint>

class Food
{
public:
    Food();
    void generate();
    QPoint getPosition();

private:
    QPoint position;
};

#endif // FOOD_H
