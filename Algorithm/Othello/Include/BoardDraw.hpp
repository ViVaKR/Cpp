
#ifndef BOARD_DRAW_HPP
#define BOARD_DRAW_HPP
#include "Board.hpp"
#include <iostream>
#include <unistd.h>
#include <vector>
class BoardDraw
{
  public:
    static void Print(const Board &board);
};
#endif
