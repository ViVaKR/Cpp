#ifndef DEMO_HPP // 만일 DEMO_HPP가 정의되어 있지 않다면
#define DEMO_HPP // DEMO_HPP를 정의하라
#include <iostream>
#include <math.h>

template <class T, class U>
class Demo
{
  private:
    T valueA;
    U valueB;
    Demo *ptr;

  public:
    static inline U staticValue{3};
    Demo();                 // 1. default constructor, 기본 생성자 (가장 기본적인 객체 생성자), 호출방법=> Demo<int, int> demoDefault;// 또는 Demo<int, int> demoDefault = Demo<int, int>();
    Demo(T a, U b);         // 2. parameterized constructor, 파라미터 생성자, 호출방법=> Demo<float, double> demo(3.14, 4.3);
    Demo(const Demo &demo); // 3. copy constructor, 복사 생성자, 호출방법=> Demo<float, double> demo_copy = demo;
    U GetValue();
    void SetValue(T a, U b);
    void Print();

    ~Demo() // 소멸자, 객체가 소멸될 때 호출되는 함수
    {
        std::cout << "소멸자 호출 " << ptr << std::endl;
    }
};

#include "../src/Demo.cpp" // DEMO_HPP가 정의되어 있지 않았다면 src/Demo.cpp를 포함하라
#endif
