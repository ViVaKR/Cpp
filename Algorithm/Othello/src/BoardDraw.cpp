#include "../Include/BoardDraw.hpp"

void BoardDraw::Print(const Board &board)
{
    system("clear");
    std::string space = std::string(3, ' ');
    std::cout << space << "\033[31m\u2766\033[0m" << space;

    for (int i = 0; i < board.size; ++i) std::cout << "\033[34m" << i << "\033[0m" << space;
    std::cout << "\n\n";

    for (int y = 0; y < board.size; ++y) {
        std::cout << space << "\033[34m" << y << "\033[0m" << space;
        for (int x = 0; x < board.size; ++x) {
            std::string symbol =
                (board.grid[y][x] == Player::USER)
                    ? "\033[31m\u2716\033[0m"
                    : (board.grid[y][x] == Player::COMPUTER ? "\033[32m\u25FC\033[0m" : "\u25E6");
            std::cout << symbol << space;
        }
        std::cout << "\n\n";
    }

    sleep(2);
    std::cout << std::string(board.size * 4 + 6, '*') << "\n\n";
}
