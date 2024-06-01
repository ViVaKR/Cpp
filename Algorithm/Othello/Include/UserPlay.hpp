#ifndef USERPLAY_HPP
#define USERPLAY_HPP
#include "Board.hpp"
#include "BoardCheck.hpp"
#include <iostream>
class UserPlay
{
  public:
    static std::pair<int, int> GetUserMove(Board &board);
};
#endif
