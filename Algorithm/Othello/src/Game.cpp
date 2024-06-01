#include "../Include/Game.hpp"

Game::Game(int size) : board(size), player(Player::USER) {}

void Game::SwitchPlayer()
{
    player = (player == Player::USER) ? Player::COMPUTER : Player::USER;
}

/// @brief Play the game
void Game::Play()
{
    while (true) {

        BoardDraw::Print(board);

        if (player == Player::USER) {
            const auto [x, y] = UserPlay::GetUserMove(board);
            BoardCheck::PlaceMark(board, x, y, Player::USER);
        } else {
            const auto [x, y] = ComputerPlay::GetBestMove(board);
            if (x == -1 && y == -1) std::cout << "Computer has no valid moves!\n";
            else BoardCheck::PlaceMark(board, x, y, Player::COMPUTER);
        }

        if (!BoardCheck::HasValidMove(board, Player::USER) && !BoardCheck::HasValidMove(board, Player::COMPUTER)) {
            BoardDraw::Print(board);
            int userScore = BoardCheck::Count(board, Player::USER);
            int computerScore = BoardCheck::Count(board, Player::COMPUTER);
            std::cout << "Game over! User: " << userScore << ", Computer: " << computerScore << "\n";
            if (userScore > computerScore) {
                std::cout << "User wins!\n";
            } else if (userScore < computerScore) {
                std::cout << "Computer wins!\n";
            } else {
                std::cout << "It's a draw!\n";
            }
            break;
        }

        SwitchPlayer();
    }
}
