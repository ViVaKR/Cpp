#pragma once
#include <iostream>

class Ground
{
  private:
    int a;
    int b;

  public:
    Ground(int a, int b);
    int getA();
    int getB();
    ~Ground();
};
