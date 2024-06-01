
#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "BoardDraw.hpp"
#include "ComputerPlay.hpp"
#include "Player.hpp"
#include "UserPlay.hpp"
#include <iostream>
#include <vector>

class Game
{
  private:
    Board board;
    Player player;

  public:
    Game(int size);
    void SwitchPlayer();
    void Play();
    ~Game() {}
};
#endif
