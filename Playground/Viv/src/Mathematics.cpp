
#include <iostream>

using namespace std;

class OperatorOverloading
{
  public:
    int x, y;
    OperatorOverloading(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(OperatorOverloading obj)
    {
        return (x == obj.x && y == obj.y);
    }

    OperatorOverloading operator+(OperatorOverloading obj)
    {
        OperatorOverloading temp(0, 0);
        temp.x = x + obj.x;
        temp.y = y + obj.y;
        return temp;
    }

    OperatorOverloading operator-(OperatorOverloading obj)
    {
        OperatorOverloading temp(0, 0);
        temp.x = x - obj.x;
        temp.y = y - obj.y;
        return temp;
    }

    OperatorOverloading operator*(OperatorOverloading obj)
    {
        OperatorOverloading temp(0, 0);
        temp.x = x * obj.x;
        temp.y = y * obj.y;
        return temp;
    }

    OperatorOverloading operator/(OperatorOverloading obj)
    {
        OperatorOverloading temp(0, 0);
        temp.x = x / obj.x;
        temp.y = y / obj.y;
        return temp;
    }

    OperatorOverloading operator%(OperatorOverloading obj)
    {
        OperatorOverloading temp(0, 0);
        temp.x = x % obj.x;
        temp.y = y % obj.y;
        return temp;
    }

    OperatorOverloading operator++()
    {
        OperatorOverloading temp(0, 0);
        temp.x = ++x;
        temp.y = ++y;
        return temp;
    }
};
