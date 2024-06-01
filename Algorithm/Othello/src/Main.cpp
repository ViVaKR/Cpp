#include "../Include/Game.hpp"
int main()
{
    int size;
    std::cout << "\033[35m"
              << "\u27A5 Enter the board size ( 6 to 12 ) \u26A9 "
              << "\033[0m";
    std::cin >> size;
    while (size < 6 || size > 12) {
        std::cout << "\033[31m";
        std::cout << "\u274C Invalid size. Enter a size between 6 and 12\n\u26A9";
        std::cout << "\033[0m";
        std::cin >> size;
    }
    std::cout << std::endl;
    Game game(size);
    game.Play();
    return 0;
}
