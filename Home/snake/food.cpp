#include "food.h"
#include <cstdlib>
#include <ctime>

Food::Food()
{
    srand(time(nullptr)); // randon number
}

void Food::generate()
{
    int x = rand() % 60; // Adjust range as needed
    int y = rand() % 40; // Adjust range as needed
    position = QPoint(x, y);
}

QPoint Food::getPosition()
{
    return position;
}
