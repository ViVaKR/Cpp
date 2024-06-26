#include <iostream>

using namespace std;

class CRectangle {
  private:
    int width;
    int height;

  public:
    CRectangle() {
        width = 1;
        height = 1;
    }
    CRectangle(int w, int h) {
        width = w;
        height = h;
    }
    int getWidth() const { return width; }
    void setWidth(int w) { width = w; }
    int getHeight() const { return height; }
    void setHeight(int h) { height = h; }
    int getArea() const { return width * height; }
    int getPerimeter() const { return 2 * (width + height); }
};
