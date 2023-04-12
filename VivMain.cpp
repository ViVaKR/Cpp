
#include <iostream>

#include "Switch/Calculate.cpp"
#include "TernaryOperator/TernaryOperator.cpp"
#include "TemperatureConvert/TemperatureConvert.cpp"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "Hello World! Fine Thanks And You" << endl;
    auto result = (10 <=> 20) > 0;
    cout << result << endl;
    
    cout << "********** 실행할 프로그램 선택하세요 (번호선택) **********" << endl
         << endl;

    cout << "(1)"
         << " Calculate" << endl
         << endl;
         
    cout << "(2)"
         << " Ternary Operator" << endl
         << endl;

    cout << "(3)"
         << " Temperature Conversion" << endl
         << endl;
         
    cout << "(100)"
         << " 종료" << endl
         << endl;

    cout << std::string(100, '*')
    << endl
    << endl;

    int choice;
    cout << "프로그램 번호 선택 >> ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        Calculate();
        break;

    case 2:
        TernaryOperator();
        break;

    case 3:
        TemperatureConvert();
        break;

    case 100:
        cout << "프로그램을 종료합니다." << endl;
        break;

    default:
        cout << "잘못된 선택입니다." << endl;
        break;
    }

    return 0;
}
