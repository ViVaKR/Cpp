// Points.cpp
#include "../headers/Points.h"

Points::Points(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Points::operator==(Points &p)
{
    return this->x == p.x && this->y == p.y;
}

Points Points::operator++()
{
    this->x++;
    this->y++;
    return *this;
}

int Points::getX()
{
    return this->x;
}

int Points::getY()
{
    return this->y;
}

Points::~Points()
{
}
