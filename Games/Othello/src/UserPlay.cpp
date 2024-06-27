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
        std::cout << "\u27A6 착점양보 \u279C ( " << board.size + 20 << " " << board.size + 20 << " )" << std::endl;
        std::cout << "\u27A6 게임종료 \u279C ( " << board.size + 10 << " " << board.size + 10 << " )" << std::endl;

        std::cout << Common::AnsiColor(205) << "\u26A6 좌표입력 \u279C (  x y  )\033[0m";
        std::cout << std::endl;

        std::cout << Common::AnsiColor(196) << "\u26A9 \033[0m";
        std::cin >> x >> y;

        if (x == board.size + 20 && y == board.size + 20) {
            std::cout << "플레이 권을 상대방에게 양보합니다.\n";
            return {board.size + 20, board.size + 20};
        }

        if (x == board.size + 10 && y == board.size + 10) {
            std::cout << "게임을 종료합니다 아무키나 누르세요 ...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();

            exit(0);
        }

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
