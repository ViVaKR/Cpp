#include "../Include/BoardCheck.hpp"
#include <iostream>

void BoardCheck::PlaceMark(Board &board, int x, int y, Player player)
{
    // 그리드에 플레이어의 착점 위치를 저장
    board.grid[y][x] = player;

    // 상대 플레이어
    Player opponent = (player == Player::USER) ? Player::COMPUTER : Player::USER;

    // 8방향 탐색
    int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    // (-1, -1), (0, -1), (1, -1), (-1, 0), (1, 0), (-1, 1), (0, 1), (1, 1)
    // 좌하, 하, 우하, 좌, 우, 좌상, 상, 우상
    for (int i = 0; i < 8; ++i) { // 8방향으로 순차적으로 쭈욱 직선 탐색
                                  // (1) 즉, 8방향으로 직선으로 탐색해 가면서 상대 플레이어가 있으면 표시 해 놓는다.
                                  // (2) 그리고 아군 돌이 나오면, 그 사이에 있는 상대 돌을 아군 돌로 뒤집는다.

        // 뒤집어야 하는 돌의 좌표를 저장하는 벡터
        std::vector<std::pair<int, int>> toFlip;

        int nx = x + dx[i];                                                // x 좌표
        int ny = y + dy[i];                                                // y 좌표

        while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) { // 보드의 범위를 벗어나지 않는 동안

            if (board.grid[ny][nx] == opponent)                            // 이동한 좌표에 상대 플레이어가 있는 경우
                toFlip.push_back({nx, ny});                                // 뒤집을대상 상대 돌의 좌표를 저장

            else if (board.grid[ny][nx] == player) {                       // 이동한 좌표에 아군이 있는 경우
                for (auto [fx, fy] : toFlip)                               // 뒤집을 대상 상대 돌의 좌표를 하나씩 꺼내서
                    board.grid[fy][fx] = player;                           // 아군 돌로 뒤집는다.
                break;
            } else
                break;

            nx += dx[i]; // 다음 X 좌표로 이동
            ny += dy[i]; // 다음 Y 좌표로 이동
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
    for (int i = 0; i < 8; ++i) {

        // 상대 플레이어가 있는지 확인
        // 상대 플레이어가 있으면 true
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 상대 플레이어가 있는지 확인하는 임시 변수
        bool hasOpponent = false;

        // 보드의 범위를 벗어나지 않는 동안
        while (nx >= 0 && nx < board.size && ny >= 0 && ny < board.size) {

            // 상대 플레이어가 있는지 확인
            if (board.grid[ny][nx] == opponent)
                hasOpponent = true;
            else if (board.grid[ny][nx] == player) { // 아군이 나오면
                if (hasOpponent)
                    return true;                     // 직전 좌표에 상대 플레이어가 있다는 표식이 있고 현재 이동한 좌표가 아군이면 true 로 리턴 (유효한 움직임, 최종 유효한 움직임이 됨)
                else
                    break;                           // 상대 플레이어가 없으면 break 하고 다음 좌표로 이동
            } else
                break;                               // 빈 공간이면 break 하고 다음 좌표로 이동

            // 다음 좌표로 이동
            // ( 예를 들어 )
            // 좌상 방향으로 x, y 좌표를 각각 -1씩 이동하는 경우,
            // 같은 방향 즉 계속 -1 씩 이동 을 반복 한다.
            // 즉, 이동하는 경로에 적이 있으면, 좌표에 일단 저장한 후 계속 이동하는 로직.
            // 다음 좌표로 이동한 후 아군이 나올때까지 계속 이동한다.
            nx += dx[i];
            ny += dy[i];
        }
    }
    return false;
}
