
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
    Game();
    Game(int size);
    void SwitchPlayer(Player &player);
    void Resize(int n);
    void Play();
    void MakeDecision();
    void GameOver();
    ~Game()
    {
        delete &board;
        delete &player;
    }
};
#endif
