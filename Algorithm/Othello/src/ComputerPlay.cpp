#include "../Include/ComputerPlay.hpp"

/// @brief Get the best move for the computer
/// @param board The game board
/// @return The best move for the computer
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
