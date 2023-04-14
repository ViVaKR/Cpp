#include <ctime>
#include <iostream>

using namespace std;

void DrawBoard(char *spaces);
void PlayerMove(char *spaces, char player);
void ComputerMove(char *spaces, char computer);
bool CheckWinner(char *spaces, char player, char computer);
bool CheckTie(char *spaces);

/// @brief ref: Bro Code
void TicTacToe() {
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    DrawBoard(spaces);

    while (running) {
        PlayerMove(spaces, player);
        DrawBoard(spaces);
        if (CheckWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (CheckTie(spaces)) {
            running = false;
            break;
        }
        ComputerMove(spaces, computer);
        DrawBoard(spaces);
        if (CheckWinner(spaces, player, computer)) {
            running = false;
            break;
        } else if (CheckTie(spaces)) {
            running = false;
            break;
        }
    }

    cout << "Thanks for playing";
}

/// @brief 보드판 그리기
/// @param spaces
void DrawBoard(char *spaces) {
    std::cout << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    cout << "     |     |     " << endl;
    std::cout << endl;
}

/// @brief 플레이어 플레이
/// @param spaces
/// @param player
void PlayerMove(char *spaces, char player) {

    int number;
    do {
        cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if (spaces[number] == ' ') {
            spaces[number] = player;
            system("clear");
            break;
        }
    } while (!number > 0 || !number < 8);
}

/// @brief 컴퓨터 플레이
/// @param spaces
/// @param computer
void ComputerMove(char *spaces, char computer) {
    int number;
    srand(time(0));
    while (true) {
        number = rand() % 9;
        if (spaces[number] == ' ') {
            spaces[number] = computer;
            system("clear");
            break;
        }
    }
}

/// @brief 승부확인
/// @param spaces
/// @param player
/// @param computer
/// @return
bool CheckWinner(char *spaces, char player, char computer) {

    // 첫번째 행
    if ((spaces[0] != ' ') && (spaces[0] == spaces[1] && spaces[1] == spaces[2])) {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    // 두번째 행
    else if ((spaces[3] != ' ') && (spaces[3] == spaces[4] && spaces[4] == spaces[5])) {
        spaces[3] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    // 세번째 행
    else if ((spaces[6] != ' ') && (spaces[6] == spaces[7] && spaces[7] == spaces[8])) {
        spaces[6] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    // 첫번째 열
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[3] && spaces[3] == spaces[6])) {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    // 두번째 열
    else if ((spaces[1] != ' ') && (spaces[1] == spaces[4] && spaces[4] == spaces[7])) {
        spaces[1] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }
    // 세번째 열
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[5] && spaces[5] == spaces[8])) {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    // 대각선 (우하 방향)
    else if ((spaces[0] != ' ') && (spaces[0] == spaces[4] && spaces[4] == spaces[8])) {
        spaces[0] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    // 대각선 (좌하 방향)
    else if ((spaces[2] != ' ') && (spaces[2] == spaces[4] && spaces[4] == spaces[6])) {
        spaces[2] == player ? cout << "YOU WIN!\n" : cout << "YOU LOSE!\n";
    }

    // 아직 승부가 나지 않았음
    else {
        return false;
    }

    return true;
}

/// @brief 무승부 가리기
/// @param spaces
/// @return
bool CheckTie(char *spaces) {
    for (int i = 0; i < 9; i++) {
        if (spaces[i] == ' ') { // 빈 곳 찾기
            return false;
        }
    }

    cout << "IT'S A TIE!" << endl;
    return true;
}
