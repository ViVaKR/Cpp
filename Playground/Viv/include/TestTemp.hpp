
#ifndef TESTTEMP_HPP
#define TESTTEMP_HPP
template <class T>
class TestTemp
{
  public:
    TestTemp();
    void SetValue(T value);
    T GetValue();
    void SetArray(T value, int i);
    T GetElem(T i);
    TestTemp &Increase(int a, int value);

  private:
    T array[5];
    T data;
};

#include "../src/TestTemp.cpp"
#endif
