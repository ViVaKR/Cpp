#include <iostream>
#include <string.h>

#include "Demo/Array.cpp"
#include "Demo/Array2D.cpp"
#include "Demo/Banking.cpp"
#include "Demo/DoWhileLoop.cpp"
#include "Demo/ForLoop.cpp"
#include "Demo/Function.cpp"
#include "Demo/If.cpp"
#include "Demo/PseudoRandom.cpp"
#include "Demo/RockPaperScissors.cpp"
#include "Demo/Strings.cpp"
#include "Demo/StuduentScore.cpp"
#include "Demo/Switch.cpp"
#include "Demo/TernaryOperator.cpp"
#include "Demo/WhileLoop.cpp"
#include "Demo/Memory.cpp"
#include "Demo/Pointers.cpp"
#include "Demo/TicTacToe.cpp"
#include "Demo/DynamicMemory.cpp"

void PrintMenu();
using namespace std;

/// @brief ./run <exec number>
/// @param argc
/// @param argv
/// @return
int main(int argc, char *argv[]) {

    // 쉘에서 시작 : true;
    // While Loop 에서 반복실행 시 : false
    bool fromShell = true;

    cout << "********** 실행할 프로그램 선택하세요 (번호선택) **********" << endl << endl;
    PrintMenu();

    long choice;

    do {
        cout << std::string(60, '*') << endl;
        if (strtol(argv[1], NULL, 10) == 100 || !fromShell) {
            PrintMenu();
            cout << "프로그램 번호 선택 >> ";
            cin >> choice;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else {
            choice = strtol(argv[1], NULL, 10);
            fromShell = false;
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
            case 13: Array(); break;
            case 14: Array2D(); break;
            case 15: Memory(); break;
            case 16: Pointers(); break;
            case 17: TicTacToe(); break;
            case 18: DynamicMemory(); break;
            case 100: cout << "프로그램을 종료합니다." << endl; break;
            default: cout << "잘못된 선택입니다." << endl; break;
        }
    } while (choice != 100);
    system("clear");

    return 0;
}

/// @brief Will Runnig Program List Menus
void PrintMenu() {
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
    cout << "(13) Array" << endl;
    cout << "(14) Array2D" << endl;
    cout << "(15) Memory" << endl;
    cout << "(16) Pointers" << endl;
    cout << "(17) Tic Tae Toe" << endl;
    cout << "(18) Dynamic Memory" << endl;
    cout << "(100) 종료" << endl;
}
