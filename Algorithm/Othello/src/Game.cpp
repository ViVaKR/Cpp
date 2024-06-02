#include "../Include/Game.hpp"

Game::Game() : board(8), player(Player::USER) {}

Game::Game(int size) : board(size), player(Player::USER) {}

void Game::SwitchPlayer(Player &player)
{
    std::cout << "Switching player from " << ((player == Player::USER) ? "USER" : "COMPUTER");
    std::cout << " -> " << ((player == Player::USER) ? "COMPUTER" : "USER") << "\n";
    std::fflush(stdin);
    Common::Sleep(2000);

    player = (player == Player::USER) ? Player::COMPUTER : Player::USER;
}

/// @brief 보드 크기 조정
/// @param n 보드 크기
void Game::Resize(int n)
{
    board.Resize(n);
}

/// @brief Play the game
void Game::Play()
{
    while (true) {

        MakeDecision();               // 게임 점수 출력

        if (player == Player::USER) { // 플레이어 차례
            // 플레이어가 수를 놓는다.
            const auto [x, y] = UserPlay::GetUserMove(board);

            // 플레이어가 패스를 선택한 경우
            if (x == board.size + 20 && y == board.size + 20) {
                player = Player::COMPUTER;
                continue;
            } else
                // 보드에 돌을 그려 넣는다.
                BoardCheck::PlaceMark(board, x, y, Player::USER);
        } else { // 컴퓨터 차례

            // 컴퓨터가 최적의 수를 찾아서 놓는다.
            const auto [x, y] = ComputerPlay::GetBestMove(board);

            if (x != -1 && y != -1)
                // 보드에 돌을 그려 넣는다.
                BoardCheck::PlaceMark(board, x, y, Player::COMPUTER);
        }

        // Check if the game is over
        if (!BoardCheck::HasValidMove(board, Player::USER) && !BoardCheck::HasValidMove(board, Player::COMPUTER)) {

            // 게임 종료
            GameOver();
        }

        // 플레이어 교체
        SwitchPlayer(player);
    }
}

/// @brief 현재 게임 점수 출력
void Game::MakeDecision()
{
    BoardDraw::Print(board);

    int userScore = BoardCheck::Count(board, Player::USER);
    int computerScore = BoardCheck::Count(board, Player::COMPUTER);

    std::cout << "\033[33m\u2728 SCORE "
              << "[ User: " << userScore << ", Computer: " << computerScore << " ] "
              << "\u2728\033[0m"
              << "\n";
}

void Game::GameOver()
{
    BoardDraw::Print(board);
    int userScore = BoardCheck::Count(board, Player::USER);
    int computerScore = BoardCheck::Count(board, Player::COMPUTER);
    std::cout << "[ Game Over! ]\n";
    std::cout << "User: " << userScore << ", Computer: " << computerScore << "\n";
    if (userScore > computerScore) {
        std::cout << "User wins!\n";
    } else if (userScore < computerScore) {
        std::cout << "Computer wins!\n";
    } else {
        std::cout << "It's a draw!\n";
    }
    std::cin.get();
    exit(0);
}
