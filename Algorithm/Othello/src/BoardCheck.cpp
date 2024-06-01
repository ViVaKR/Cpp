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
    for (int i = 0; i < 8; ++i) {

        std::vector<std::pair<int, int>> toFlip;

        int nx = x + dx[i];
        int ny = y + dy[i];

        while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {

            if (board.grid[ny][nx] == opponent) toFlip.push_back({nx, ny});

            else if (board.grid[ny][nx] == player) {
                for (auto [fx, fy] : toFlip)
                    board.grid[fy][fx] = player;
                break;
            } else break;

            nx += dx[i];
            ny += dy[i];
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

/// @brief 유효한 움직임인지 확인
/// @param board 보드
/// @param x 가로 좌표
/// @param y 세로 좌표
/// @param player user or computer
/// @return true if the move is valid, false otherwise
bool BoardCheck::IsValidMove(const Board &board, int x, int y, Player player)
{
    // 이미 돌이 놓여있는 경우 (false)
    if (board.grid[y][x] != Player::NONE) return false;

    // 현재 플레이어와 대응 되는 상대 플레이어, user -> computer, computer -> user
    Player opponent = (player == Player::USER) ? Player::COMPUTER : Player::USER;

    // 8방향 탐색
    // 좌상, 상, 우상, 좌, 우, 좌하, 하, 우하
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    // 8방향 탐색
    // x : 착점한 가로 좌표, y : 착점한 세로 좌표
    for (int i = 0; i < 8; i++) {

        // 상대 플레이어가 있는지 확인
        // 상대 플레이어가 있으면 true
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 상대 플레이어가 있는지 확인하는 임시 변수
        bool hasOpponent = false;

        // 보드의 범위를 벗어나지 않는 동안
        bool check = nx >= 0 && nx < board.size && ny >= 0 && ny < board.size;

        while (check) {

            // 상대 플레이어가 있는지 확인
            check = nx >= 0 && nx < board.size && ny >= 0 && ny < board.size;

            if (board.grid[ny][nx] == opponent) hasOpponent = true; // 상대 플레이어가 있으면 true
            else if (board.grid[ny][nx] == player) {                // 아군이 나오면
                if (hasOpponent) return true;                       // 직전 좌표에 상대 플레이어가 있다는 표식이 있고 현재 이동한 좌표가 아군이면 true 로 리턴 (유효한 움직임, 최종 유효한 움직임이 됨)
                else break;                                         // 상대 플레이어가 없으면 break 하고 다음 좌표로 이동
            } else break;                                           // 빈 공간이면 break 하고 다음 좌표로 이동

            // 다음 좌표로 이동
            // ( 예를 들어 )
            // 좌상 방향으로 x, y 좌표를 각각 -1씩 이동하는 경우,
            // 같은 방향 즉 계속 -1 씩 이동 을 반복 한다.
            // 즉, 이동하는 경로에 적이 있으면, 좌표에 일단 저장한 후 계속 이동하는 로직.
            // 다음 좌표로 이동한 후 아군이 나올때까지 계속 이동한다.
            nx += dx[i];
            ny += dy[i];
        }

        // if (check) {
        //     hasOpponent = board.grid[ny][nx] == opponent;
        //     if (board.grid[ny][nx] == player) {
        //         if (hasOpponent) return true;
        //     }
        // }
    }
    return false;
}
