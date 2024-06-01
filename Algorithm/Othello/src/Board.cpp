#include "../Include/Board.hpp"
Board::Board(int n) : size(n)
{
    grid.resize(size, std::vector<Player>(size, Player::NONE));
    int mid = size / 2;

    // Initialize the board with 4 pieces in the center
    grid[mid - 1][mid - 1] = Player::COMPUTER;
    grid[mid][mid] = Player::COMPUTER;
    grid[mid - 1][mid] = Player::USER;
    grid[mid][mid - 1] = Player::USER;
}
