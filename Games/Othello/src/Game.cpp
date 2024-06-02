#include "../Include/Game.hpp"

Game::Game() : board(8), player(Player::USER) {}

Game::Game(int size) : board(size), player(Player::USER) {}

void Game::SwitchPlayer(Player &player)
{
    std::cout << "Switching player from " << ((player == Player::USER) ? "USER" : "COMPUTER");
    std::cout << " -> " << ((player == Player::USER) ? "COMPUTER" : "USER") << "\n";
    std::fflush(stdin);
    Common::Sleep(1500);

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

        if (player == Player::USER) { // USER 차례
            // 플레이어가 수를 놓는다.
            const auto [x, y] = UserPlay::GetUserMove(board);

            // 플레이어가 패스를 선택한 경우
            if (x == board.size + 20 && y == board.size + 20) {
                player = Player::COMPUTER;
                continue;
            } else
                // 보드에 돌을 그려 넣는다.
                BoardCheck::PlaceMark(board, x, y, Player::USER);
            std::fflush(stdin);
        } else { // 컴퓨터 차례

            // 컴퓨터가 최적의 수를 찾아서 놓는다.
            const auto [x, y] = ComputerPlay::GetBestMove(board);

            if (x != -1 && y != -1)
                // 보드에 돌을 그려 넣는다.
                BoardCheck::PlaceMark(board, x, y, Player::COMPUTER);
            std::fflush(stdin);
        }

        bool hasUserMove = BoardCheck::HasValidMove(board, Player::USER);
        bool hasComputerMove = BoardCheck::HasValidMove(board, Player::COMPUTER);

        // 플레이어와 컴퓨터 모두 이동할 수 없는 경우
        // `!BoardCheck::HasValidMove(board, Player::USER) && !BoardCheck::HasValidMove(board, Player::COMPUTER)`
        if (!hasUserMove && !hasComputerMove) {
            // 게임 종료
            std::cout << "양쪽 플레이어가 더이상 이동할 자리가 남아 있지 않습니다.\n게임결과를 확인하겠습니다. 엔터키를 누르세요...\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            GameOver();
        }

        // 플레이어가 이동할 수 없는 경우
        if (player == Player::USER) {
            if (!hasUserMove) {
                BoardDraw::Print(board);

                // 컴퓨터는 이동할수 있지만, 플레이어는 이동할 수 없는 경우
                if (hasComputerMove) {
                    std::cout
                        << Common::AnsiColor(226)
                        << "플레이어가 더이상 이동할 자리가 남아 있지 않으나, 컴퓨터는 이동할 자리가 남아있습니다.\n"
                        << "착수 권한을 컴퓨터에게 이전합니다. 계속 진행하려면? 엔터키를 누르세요...\n"
                        << "\033[0m";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin.get();

                    player = Player::COMPUTER;
                    continue;
                }
                // // 플레이어와 컴퓨터 모두 이동할 수 없는 경우
                // std::cout
                //     << Common::AnsiColor(226)
                //     << "모든 플레이어에게 더이상 이동할 자리가 남아 있지 않습니다.\n"
                //     << "게임결과를 확인하겠습니다. 엔터키를 누르세요..."
                //     << "\033[0m\n";
                // std::cin.clear();
                // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                // std::cin.get();
                // GameOver();
            }
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

/// @brief 게임 종료, 스코어 출력
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
