#include "../Include/ComputerPlay.hpp"

std::pair<int, int> ComputerPlay::GetBestMove(Board &board)
{
    for (int y = 0; y < board.size; ++y) {
        for (int x = 0; x < board.size; ++x) {
            if (BoardCheck::IsValidMove(board, x, y, Player::COMPUTER)) {
                std::cout << "\033[33m";
                std::cout << "\u2620 Computer moved to ( " << x << ", " << y << " )" << std::endl;
                std::cout << "\033[0m";
                return {x, y};
            }
        }
    }
    return {-1, -1};
}
