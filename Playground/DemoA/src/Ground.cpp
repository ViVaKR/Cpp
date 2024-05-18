#include "../include/Ground.h"
Ground::Ground(int a, int b)
{
    this->a = a;
    this->b = b;
}

int Ground::getA() { return a; }
int Ground::getB() { return b; }
Ground::~Ground()
{
    std::cout << "Ground destroyed" << std::endl;
}
