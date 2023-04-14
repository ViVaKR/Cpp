#include <ctime>
#include <iostream>

using namespace std;

char GetUserChoice();
char GetComputerChoice();
void ShowChoice(char choice);
void ChooseWinner(char player, char computer);

/// @brief 가위바위보 시작점
void RockPaperScissors() {

    char player;
    char computer;
    std::cout << endl;

    // 사람
    player = GetUserChoice();
    cout << "당신의 선택은\t(You choice):\t\t";
    ShowChoice(player);

    // 컴퓨터
    computer = GetComputerChoice();
    cout << "컴퓨터의 선택은\t(Computer's choice):\t";
    ShowChoice(computer);

    // 승부보기
    ChooseWinner(player, computer);
}

/// @brief 사람 선택
/// @return 
char GetUserChoice() {

    char player;
    bool check;
    cout << "가위 바위 보 게임!" << endl;

    do {
        cout << "다음중 하나를 선택하세요 (Choose one of the follwing)\n";
        cout << string(60, '*') << endl;
        cout << "(S) -\t가위\t(Scissors)" << endl;
        cout << "(R) -\t바위\t(Rock)" << endl;
        cout << "(P) -\t보\t(Paper)" << endl;
        cout << ">>> ";
        std::cin >> player;
        player = tolower(player, locale());

        check = player != 's' && player != 'r' && player != 'p';
        // if -> `s` : 1 && 0 && 0 => 0 (false), 만일 위 셋 중에 하나라도 있으면 거짓
        // if -> `a` : 0 && 0 && 0 => 1 (true), 만일 위 셋 중에 하나라도 없으면 참
        // 즉 위 셋중에 하나라도 있어야 루프를 빠져 나감.

    } while (check);

    return player;
}

/// @brief 컴퓨터 선택
/// @return 
char GetComputerChoice() {

    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1: return 's'; break;
        case 2: return 'r'; break;
        case 3: return 'p'; break;
    }

    return 0;
}

/// @brief 선택한 내용 출력
/// @param choice 
void ShowChoice(char choice) {
    switch (choice) {
        case 's': cout << "가위 (Scissors)" << endl; break;
        case 'r': cout << "바위 (Rock)" << endl; break;
        case 'p': cout << "보 (Paper)" << endl; break;
        default: break;
    }
}

/// @brief 승부결정
/// @param player 
/// @param computer 
void ChooseWinner(char player, char computer) {

    switch (player) {
        case 's': { // 가위
            switch (computer) {
                case 's': cout << "비김 (It's a tie!)" << endl; break;
                case 'r': cout << "패배 (You lose!)" << endl; break;
                case 'p': cout << "승리 (You win!)" << endl; break;
            }
        } break;
        case 'r': { // 바위
            switch (computer) {
                case 's': cout << "승리 (You win!)" << endl; break;
                case 'r': cout << "비김 (It's a tie!)" << endl; break;
                case 'p': cout << "패배 (You lose!)" << endl; break;
            }
        } break;
        case 'p': { // 보
            switch (computer) {
                case 's': cout << "패배 (You lose!)" << endl; break;
                case 'r': cout << "승리 (You win!)" << endl; break;
                case 'p': cout << "비김 (It's a tie!)" << endl; break;
            }
        }break;
    }
}
