#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>

template <class T>
class Utils
{
  private:
    T data_a;
    T data_b;

  public:
    Utils(T a, T b) : data_a(a), data_b(b) {}
    void Print()
    {
        system("clear");
        std::cout.precision(16);
        std::cout << "\n\u27A5 " << (T)data_a << ", " << (T)data_b << std::endl
                  << (T)10 / 3 << std::endl;
    }

    T Add();

    void ToBinary(int num);
    ~Utils() {}
};

#include "../src/Utils.cpp"
#endif
