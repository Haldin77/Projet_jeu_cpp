#include "Position.hpp"

int Position::x() { return xpos; }
int Position::y() { return ypos; }

void Position::init()
{
    xpos = 0;
    ypos = 0;
}
void Position::update()
{
    xpos++;
    ypos++;
}
void Position::setPos(int x, int y)
{
    xpos = x;
    ypos = y;
}