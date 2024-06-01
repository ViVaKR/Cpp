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
    Common() {}
    Common(int argc, char *argv[], int low, int hight) : m_argc(argc), m_argv(argv)
    {
        if (m_argc > 1)
            std::cout << "Input Args[1]: " << m_argv[1] << "!" << std::endl;

        _low = 6;
        _high = 12;
    }

    int GetLow()
    {
        return _low;
    }
    int GetHigh()
    {
        return _high;
    }

    static void ClearScreen()
    {
#if _WIN32
        std::cout << "Hello, Windows!" << std::endl;
        system("cls");
#elif __APPLE__
        std::cout << "Hello, Mac OS X!" << std::endl;
        system("clear");
#elif __linux__
        std::cout << "Hello, Linux!" << std::endl;
        system("clear");
#elif __unix__
        std::cout << "Hello, Unix!" << std::endl;
        system("clear");
#elif __FreeBSD__
        std::cout << "Hello, FreeBSD!" << std::endl;
        system("clear");
#else
        std::cout << "Hello, Unknown!" << std::endl;
        system("clear");
#endif
    }

    // Returns true if x is in range [low..high], else false
    bool InRange(int value)
    {
        return value >= _low && value <= _high;
    }

    static std::string AnsiColor(int color)
    {
        return "\033[38;5;" + std::to_string(color) + "m";
    }
    ~Common() {}
};

#endif
