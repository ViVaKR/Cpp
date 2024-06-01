#include "../Include/UserPlay.hpp"

/// @brief 에러 메시지 출력
/// @param msg 메시지
/// @param check 체크
void ErrorMsg(const std::string &msg, bool &check)
{
    std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    check = false;
}

/// @brief 유저의 돌을 놓을 위치를 입력받는 함수
/// @param board 게임판
/// @return 유저의 돌을 놓을 위치
std::pair<int, int> UserPlay::GetUserMove(Board &board)
{
    // 유저의 돌을 놓을 위치 (양의 정수만 입력받수 있음)
    unsigned x;
    unsigned y;

    // Check if the input is valid
    bool check = false;

    // Repeat until the user enters a valid move
    while (!check) {

        // Print the message to the user
        std::cout << "\u2620 "
                  << "Enter Your Move ";
        std::cout << "(0, 0) ~ "
                  << "(" << board.size - 1 << ", " << board.size - 1 << ")";
        std::cout << std::endl;
        std::cout << "( \033[31m\u2716\033[0m ) \u269E x y \u269F";
        std::cout << std::endl;
        std::cout << "\u26A9 ";
        std::cin >> x >> y;

        // Check if the input is valid (integer and in range 0 ~ board.size - 1)
        if (!std::cin.good()) {
            ErrorMsg("양의 정수만 입력하여 주세요", check);
            continue;
        }

        // Check if the input is in the range 0 ~ board.size - 1
        if (x >= board.size || y >= board.size) {
            ErrorMsg("보드의 범위를 벗어났습니다. 다시 입력해주세요.", check);
            continue;
        }

        // Check if the move is valid
        if (!BoardCheck::IsValidMove(board, x, y, Player::USER)) {
            ErrorMsg("이미 돌이 놓여있거나 놓을 수 없는 위치입니다. 다시 입력해주세요.", check);
            continue;
        }

        // If the input is valid, exit the loop
        check = true;
    }

    // Return the user's move
    return {x, y};
}
