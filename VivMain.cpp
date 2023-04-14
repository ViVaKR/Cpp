#include <iostream>
#include <string.h>

#include "Demo/Banking.cpp"
#include "Demo/ForLoop.cpp"
#include "Demo/Function.cpp"
#include "Demo/PseudoRandom.cpp"
#include "Demo/DoWhileLoop.cpp"
#include "Demo/Strings.cpp"
#include "Demo/WhileLoop.cpp"
#include "Demo/Switch.cpp"
#include "Demo/If.cpp"
#include "Demo/TernaryOperator.cpp"
#include "Demo/RockPaperScissors.cpp"
#include "Demo/StuduentScore.cpp"

using namespace std;

/// @brief ./run <exec number>
/// @param argc 
/// @param argv 
/// @return 
int main(int argc, char *argv[]) {

    cout << "********** 실행할 프로그램 선택하세요 (번호선택) **********" << endl << endl;
    cout << "(1) Switch" << endl;
    cout << "(2) Ternary Operator" << endl;
    cout << "(3) If" << endl;
    cout << "(4) Strings" << endl;
    cout << "(5) While Loop" << endl;
    cout << "(6) Do While Loop" << endl;
    cout << "(7) For Loop" << endl;
    cout << "(8) Random Number" << endl;
    cout << "(9) Functions" << endl;
    cout << "(10) Banking" << endl;
    cout << "(11) RockPaperScissors" << endl;
    cout << "(12) StudentScore" << endl;
    cout << "(100) 종료" << endl;

    cout << std::string(60, '*') << endl;

    long choice;
    if (strtol(argv[1], NULL, 10) == 100) {
        cout << "프로그램 번호 선택 >> ";
        cin >> choice;
    } else {
        choice = strtol(argv[1], NULL, 10);
    }

    cout << "## You Choice (" << choice << ") ##" << endl;
    std::cout << endl;
    
    switch (choice) {
        case 1: Switch(); break;
        case 2: TernaryOperator(); break;
        case 3: If(); break;
        case 4: Strings(); break;
        case 5: WhileLoop(); break;
        case 6: DoWhileLoop(); break;
        case 7: ForLoop(); break;
        case 8: PseudoRandom(); break;
        case 9: MainFunction(); break;
        case 10: Banking(); break;
        case 11: RockPaperScissors(); break;
        case 12: StudentScore(); break;
        case 100: cout << "프로그램을 종료합니다." << endl; break;
        default: cout << "잘못된 선택입니다." << endl; break;
    }
    return 0;
}
