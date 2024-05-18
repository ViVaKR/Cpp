
#ifndef TESTTEMP_HPP
#define TESTTEMP_HPP
template <class T>
class TestTemp
{
  public:
    TestTemp();
    void SetValue(T value);
    T GetValue();

  private:
    T data;
};

#include "../src/TestTemp.cpp"
#endif
