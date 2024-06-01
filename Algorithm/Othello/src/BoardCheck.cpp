#include "../Include/BoardCheck.hpp"
#include <iostream>

void BoardCheck::PlaceMark(Board &board, int x, int y, Player player)
{
    board.grid[y][x] = player;
    Player opponent = (player == Player::USER) ? Player::COMPUTER : Player::USER;
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // (-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)
    // 좌하, 하, 우하, 좌, 우, 좌상, 상, 우상
    for (int dir = 0; dir < 8; ++dir) {

        std::vector<std::pair<int, int>> toFlip;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {

            if (board.grid[ny][nx] == opponent) toFlip.push_back({nx, ny});

            else if (board.grid[ny][nx] == player) {
                for (auto [fx, fy] : toFlip)
                    board.grid[fy][fx] = player;
                break;
            } else break;

            nx += dx[dir];
            ny += dy[dir];
        }
    }
}

bool BoardCheck::HasValidMove(const Board &board, Player player)
{
    for (int y = 0; y < board.size; ++y) {
        for (int x = 0; x < board.size; ++x) {
            if (IsValidMove(board, x, y, player))
                return true;
        }
    }
    return false;
}

int BoardCheck::Count(const Board &board, Player player)
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

bool BoardCheck::IsValidMove(const Board &board, int x, int y, Player player)
{
    if (board.grid[y][x] != Player::NONE) return false;

    Player opponent = (player == Player::USER) ? Player::COMPUTER : Player::USER;
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        bool hasOpponent = false;
        while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {

            if (board.grid[ny][nx] == opponent) hasOpponent = true;
            else if (board.grid[ny][nx] == player) {
                if (hasOpponent) return true;
                else break;
            } else break;

            nx += dx[dir];
            ny += dy[dir];
        }
    }
    return false;
}
