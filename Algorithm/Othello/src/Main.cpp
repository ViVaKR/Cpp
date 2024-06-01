
#include "../Include/Common.hpp"

/// @brief Entry point of the program
/// @param argc The number of command line arguments
/// @param argv The command line arguments
/// @return 0 if the program exits successfully, 1 otherwise
int main(int argc, char *argv[])
{
    // Create a Common object
    // Pass the command line arguments (argc, *argv[]) and the range of the board size (6, 12)
    Common common(argc, argv, 6, 12);

    // Clear the screen
    // common.ClearScreen();
    Common::ClearScreen();

    for (int i = 1; i < 256; i++) {
        std::string ansi = std::format("\033[38;5;{}m", i - 1);
        std::string text = std::format("[38;5;{:-3}] ", i - 1);
        std::cout << ansi << text;
        if (i % 12 == 0)
            std::cout << std::endl;
    }
    std::cout << "\x1b[0m\n";

    // Print the welcome message
    std::cout << "\033[1;95m"
              << "\t\t\u269E Welcome to the Othello Game \u269F"
              << "\033[0m"
              << std::endl;

    int size;

    // Check if the input is valid
    bool check = true;

    // Get the board size from the user
    do {
        std::cout << "\033[1;94m \u276A Enter the board size, Between ";
        std::cout << common.GetLow(); // Get the low value (6)
        std::cout << " and ";
        std::cout << common.GetHigh();
        std::cout << " \u276B";
        std::cout << "\033[0m\n";

        // Get the board size from the user
        std::cout << "\033[1;94m"
                  << "\u26A9 ";

        // clear the input buffer
        std::cin.clear();

        // Get the board size from the user
        std::cin >> size;

        // Check if the input is valid (integer and in range 6 ~ 12)
        check = !(std::cin.good()) || !common.InRange(size);
        if (check) {
            std::cout << "\033[31m";
            std::cout << "\u274C Invalid Input Board Size!\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

    } while (check); // Repeat until the user enters a valid size (6 ~ 12)

    // Reset the color
    std::cout << "\033[0m";

    // Create a Game object
    Game game(size);

    // --> (1) Start the game
    game.Play();

    return 0;
}
