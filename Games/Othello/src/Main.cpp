
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

    // Print the welcome message
    std::cout << Common::AnsiColor(207)
              << "\t\t\tu269E OTHELLO \u269F"
              << "\033[0m"
              << std::endl;

    int size;

    // Check if the input is valid
    bool check = true;

    // Get the board size from the user
    do {
        std::cout << std::endl;
        std::cout << Common::AnsiColor(155) << "\u26A6 보드크기 ( ";
        std::cout << common.GetLow(); // Get the low value (6)
        std::cout << " \u2620 ";
        std::cout << common.GetHigh();
        std::cout << " )\n";

        // Get the board size from the user
        std::cout << "\u26A9 \033[0m";

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
    // common.StartGame(size);

    return 0;
}
