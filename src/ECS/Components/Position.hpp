#ifndef POSITION_HPP
#define POSITION_HPP

#include "ECS.hpp"

class Position : public Component
{
private:
    int xpos;
    int ypos;

public:
    Position(int x, int y);
    int x();
    int y();
    void init();
    void update();
    void setPos(int x, int y);
};

#endif /*POSITION_HPP*/