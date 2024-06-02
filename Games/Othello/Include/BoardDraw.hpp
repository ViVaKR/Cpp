
#ifndef BOARD_DRAW_HPP
#define BOARD_DRAW_HPP
#include "Board.hpp"
#include "Common.hpp"
#include <algorithm>
#include <format>
#include <iostream>
#include <iterator>
#include <string>
#include <unistd.h>
#include <vector>

class BoardDraw
{
  public:
    static void Print(const Board &board);
    ~BoardDraw() {}
};
#endif
