
#include <iostream>
using namespace std;

class Circle
{
  private:
    int radius;

  public:
    Circle();
    Circle(int r);
    double getArea();
    void increase();
    int getRadius();
    void setRadius(int);
    ~Circle();
};

Circle::Circle()
{
    radius = 1;
}

Circle::Circle(int r)
{
    radius = r;
}

double Circle::getArea()
{
    return 3.14 * radius * radius;
}

Circle::~Circle()
{
    cout << "소멸자 실행 radius = " << radius << endl;
}

void Circle::increase()
{
    radius++;
}

int Circle::getRadius()
{
    return radius;
}

void Circle::setRadius(int r)
{
    radius = r;
}
