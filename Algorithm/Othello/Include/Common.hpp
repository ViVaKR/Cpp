#ifndef COMMON_HPP
#define COMMON_HPP

#include "../Include/Game.hpp"

#include <iostream>

class Common
{
  private:
    int m_argc;
    char **m_argv;
    int _low;
    int _high;

  public:
    Common(int argc, char *argv[], int low, int hight);
    void StartGame(int size);
    int GetLow();
    int GetHigh();
    static void ClearScreen();
    static void Sleep(int milliseconds);
    bool InRange(int value);
    static std::string AnsiColor(int color);
    ~Common();
};

#endif
