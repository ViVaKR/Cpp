#ifndef COMPUTERPLAY_HPP
#define COMPUTERPLAY_HPP
#include "Board.hpp"
#include "BoardCheck.hpp"
#include <iostream>
class ComputerPlay
{
  public:
    static std::pair<int, int> GetBestMove(Board &board);
};
#endif
