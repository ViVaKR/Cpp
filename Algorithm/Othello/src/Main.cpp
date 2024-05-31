#include "./Board.cpp"
#include <iostream>
int main()
{
    int size;
    std::cout << "Enter the board size (6 to 12): ";
    std::cin >> size;
    while (size < 6 || size > 12) {
        std::cout << "Invalid size. Enter a size between 6 and 12: ";
        std::cin >> size;
    }
    Game game(size);
    game.play();
    return 0;
    return 0;
}
