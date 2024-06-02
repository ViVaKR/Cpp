#include "../Include/ComputerPlay.hpp"

/// @brief 컴퓨터가 가장 좋은 수를 찾는 함수.
/// @param board 게임판
/// @return 가장 좋은 수의 좌표
std::pair<int, int> ComputerPlay::GetBestMove(Board &board)
{
    for (int y = 0; y < board.size; ++y) {
        for (int x = 0; x < board.size; ++x) {

            // Check if the move is valid
            if (BoardCheck::IsValidMove(board, x, y, Player::COMPUTER)) {
                return {x, y};
            }
        }
    }
    return {-1, -1};
}
