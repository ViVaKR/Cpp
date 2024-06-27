
#ifndef BOARD_CHECK_HPP
#define BOARD_CHECK_HPP
#include "./Board.hpp"
#include "./Common.hpp"
#include "./Player.hpp"

class BoardCheck
{
  public:
    static bool IsValidMove(const Board &board, int x, int y, Player player);
    static void PlaceMark(Board &board, int x, int y, Player player);
    static bool HasValidMove(const Board &board, Player player);
    static int Count(const Board &board, Player player);
    ~BoardCheck() {}
};
#endif
