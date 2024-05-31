
#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <limits>
#include <time.h>
#include <unistd.h>
#include <vector>

enum class Player
{
    NONE,
    USER,
    COMPUTER
};

class Board
{
  public:
    std::vector<std::vector<Player>> grid;
    const int size;

    Board(int n) : size(n)
    {
        grid.resize(size, std::vector<Player>(size, Player::NONE));
        int mid = size / 2;
        grid[mid - 1][mid - 1] = Player::COMPUTER;
        grid[mid][mid] = Player::COMPUTER;
        grid[mid - 1][mid] = Player::USER;
        grid[mid][mid - 1] = Player::USER;
    }
};

class BoardDraw
{
  public:
    static void print(const Board &board)
    {
        std::string space = std::string(3, ' ');
        std::cout << space << "\u2748" << space;
        for (int i = 0; i < board.size; ++i)
            std::cout << i << space;
        std::cout << "\n\n";

        for (int y = 0; y < board.size; ++y) {
            std::cout << space << y << space;
            for (int x = 0; x < board.size; ++x) {
                char symbol = board.grid[y][x] == Player::USER ? 'X' : board.grid[y][x] == Player::COMPUTER ? 'O'
                                                                                                            : '.';
                std::cout << symbol << space;
            }
            std::cout << "\n\n";
        }
        sleep(2);
        std::cout << std::string(board.size * 4 + 6, '*') << "\n\n";
    }
};

class BoardCheck
{
  public:
    static bool isValidMove(const Board &board, int x, int y, Player player)
    {
        if (board.grid[y][x] != Player::NONE)
            return false;
        Player opponent = (player == Player::USER) ? Player::COMPUTER : Player::USER;
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int dir = 0; dir < 8; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            bool hasOpponent = false;
            while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {
                if (board.grid[ny][nx] == opponent) {
                    hasOpponent = true;
                } else if (board.grid[ny][nx] == player) {
                    if (hasOpponent)
                        return true;
                    else
                        break;
                } else {
                    break;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
        return false;
    }

    static void placeMark(Board &board, int x, int y, Player player)
    {
        board.grid[y][x] = player;
        Player opponent = (player == Player::USER) ? Player::COMPUTER : Player::USER;
        int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        for (int dir = 0; dir < 8; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            std::vector<std::pair<int, int>> toFlip;
            while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {
                if (board.grid[ny][nx] == opponent) {
                    toFlip.push_back({nx, ny});
                } else if (board.grid[ny][nx] == player) {
                    for (auto [fx, fy] : toFlip) {
                        board.grid[fy][fx] = player;
                    }
                    break;
                } else {
                    break;
                }
                nx += dx[dir];
                ny += dy[dir];
            }
        }
    }

    static bool hasValidMove(const Board &board, Player player)
    {
        for (int y = 0; y < board.size; ++y) {
            for (int x = 0; x < board.size; ++x) {
                if (isValidMove(board, x, y, player))
                    return true;
            }
        }
        return false;
    }

    static int count(const Board &board, Player player)
    {
        int count = 0;
        for (const auto &row : board.grid) {
            for (const auto &cell : row) {
                if (cell == player)
                    ++count;
            }
        }
        return count;
    }
};
class UserPlay
{
  public:
    static std::pair<int, int> getUserMove(const Board &board)
    {
        int x, y;
        while (true) {
            std::cout << "(Player -> X) Enter your move (x y): ";
            std::cin >> x >> y;

            if (std::cin.fail() || x < 0 || x >= board.size || y < 0 || y >= board.size || !BoardCheck::isValidMove(board, x, y, Player::USER)) {
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
};
class ComPlay
{
  public:
    static std::pair<int, int> getBestMove(Board &board)
    {
        for (int y = 0; y < board.size; ++y) {
            for (int x = 0; x < board.size; ++x) {
                if (BoardCheck::isValidMove(board, x, y, Player::COMPUTER)) {
                    std::cout << "Computer moved to ( " << x << ", " << y << " )" << std::endl;
                    return {x, y};
                }
            }
        }
        return {-1, -1};
    }
};

class Game
{
  private:
    Board board;
    Player currentPlayer;

  public:
    Game(int size) : board(size), currentPlayer(Player::USER) {}

    void switchPlayer()
    {
        currentPlayer = (currentPlayer == Player::USER) ? Player::COMPUTER : Player::USER;
    }

    void play()
    {
        while (true) {
            BoardDraw::print(board);
            if (currentPlayer == Player::USER) {
                auto [x, y] = UserPlay::getUserMove(board);
                BoardCheck::placeMark(board, x, y, Player::USER);
            } else {
                auto [x, y] = ComPlay::getBestMove(board);
                if (x == -1 && y == -1) {
                    std::cout << "Computer has no valid moves!\n";
                } else {
                    BoardCheck::placeMark(board, x, y, Player::COMPUTER);
                }
            }

            if (!BoardCheck::hasValidMove(board, Player::USER) && !BoardCheck::hasValidMove(board, Player::COMPUTER)) {
                BoardDraw::print(board);
                int userScore = BoardCheck::count(board, Player::USER);
                int computerScore = BoardCheck::count(board, Player::COMPUTER);
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
            switchPlayer();
        }
    }
};

#endif
