#ifndef DEMO_HPP                   // 만일 DEMO_HPP가 정의되어 있지 않다면
    #include "../include/Demo.hpp" // DEMO_HPP가 정의되어 있지 않다면 include/Demo.hpp를 포함하라
    #include <iostream>

void Print()
{
    std::cout << "헤더가 정의 되어 있지 않습니다." << std::endl;
}
#else // DEMO_HPP가 정의되어 있다면
// Default constructor
template <class T, class U>
Demo<T, U>::Demo()
{
    valueA = 1;
    valueB = 1;
    ptr = nullptr;
    ptr = this;
    staticValue = 7;
}

// Parameterized constructor
template <typename T, typename U>

Demo<T, U>::Demo(T a, U b)
{
    valueA = a;
    valueB = b;
    staticValue = 5;
}

// Copy constructor
template <class T, class U>
Demo<T, U>::Demo(const Demo &demo)
{
    valueA = demo.valueA;
    valueB = demo.valueB;
}

// Get value
template <typename T, typename U>
inline U Demo<T, U>::GetValue()
{
    return sqrt(pow(valueA, 2) * pow(valueB, 2));
}

// Set value
template <class T, class U>
void Demo<T, U>::SetValue(T a, U b)
{
    valueA = a;
    valueB = b;
}

template <class T, class U>
void Demo<T, U>::Print()
{
    std::cout << "Value A: " << valueA << "\nValue B: " << valueB << std::endl;
}

#endif
