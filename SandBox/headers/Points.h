// Points.h
#ifndef Points_H
#define Points_H

class Points
{
  private:
    int x;
    int y;

  public:
    Points(int x, int y);
    bool operator==(Points &p);
    Points operator++();
    int getX();
    int getY();
    ~Points();
};
#endif
