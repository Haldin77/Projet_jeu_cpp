#include "Position.hpp"

int Position::x() { return xpos; }
int Position::y() { return ypos; }

Position::Position(int x, int y)
{
    xpos = x;
    ypos = y;
}

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