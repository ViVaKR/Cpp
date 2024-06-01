#include "../Include/UserPlay.hpp"

std::pair<int, int> UserPlay::GetUserMove(Board &board)
{
    int x;
    int y;
    while (true) {
        std::cout << "(Player -> X) Enter your move (x y): ";
        std::cin >> x >> y;

        if (std::cin.fail() || x < 0 || x >= board.size || y < 0 || y >= board.size || !BoardCheck::IsValidMove(board, x, y, Player::USER)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid move. Try again.\n";
        } else {
            std::cout << "You moved to ( " << x << ", " << y << " )" << std::endl;
            break;
        }
    }
    return {x, y};
}
