#include <iostream>
#include <string.h>

#include "Switch/Calculate.cpp"
#include "TernaryOperator/TernaryOperator.cpp"
#include "TemperatureConvert/TemperatureConvert.cpp"
#include "DemoStrings.cpp"
#include "DemoWhileLoop.cpp"
#include "DemoDoWhileLoop.cpp"
#include "Demo/ForLoop.cpp"
#include "Demo/PseudoRandom.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    // 컴파일러 테스트
    // cout << "Hello World! Fine Thanks And You" << endl;
    // auto result = (10 <=> 20) > 0;
    // cout << result << endl;
    // 테스트 끝

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

    cout << "(4)"
         << " Strings" << endl
         << endl;

    cout << "(5)"
         << " While Loop" << endl
         << endl;

    cout << "(6)"
         << " Do While Loop" << endl
         << endl;

    cout << "(7)"
         << " For Loop" << endl
         << endl;

    cout << "(8)"
         << " Random Number" << endl
         << endl;

    cout << "(100)"
         << " 종료" << endl
         << endl;

    cout << std::string(60, '*')
         << endl
         << endl;

    long choice;
    if (strtol(argv[1], NULL, 10) == 100)
    {
        cout << "프로그램 번호 선택 >> ";
        cin >> choice;
    }
    else
    {
        choice = strtol(argv[1], NULL, 10);
    }
    
    cout << "You Choice " << choice << endl;

    // switch (choice)
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

    case 4:
        DemoStrings();
        break;

    case 5:
        DemoWhileLoop();
        break;

    case 6:
        DoWhileLoop();
        break;

    case 7:
        ForLoop();
        break;

    case 8:
        PseudoRandom();
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
