
#ifndef BOARD_HPP
#define BOARD_HPP
#include "Player.hpp"
#include <vector>

class Board
{
  public:
    int size;
    std::vector<std::vector<Player>> grid;
    Board(int n);
    ~Board() {}
};
#endif
