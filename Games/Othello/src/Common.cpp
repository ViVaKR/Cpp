#include "../Include/Common.hpp"

Common::Common(int argc, char *argv[], int low, int hight)
    : m_argc(argc), m_argv(argv), _low(low), _high(hight)
{
    if (m_argc > 1)
        std::cout << "Input Args[1]: " << m_argv[1] << "!" << std::endl;
    _low = 6;
    _high = 12;
}
void Common::StartGame(int size)
{
    // m_game->Resize(size);
    // m_game->Play();
}

void Common::ClearScreen()
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

void Common::Sleep(int milliseconds)
{
#if _WIN32
    Sleep(milliseconds);
#elif __APPLE__
    usleep(milliseconds * 1000);
#elif __linux__
    usleep(milliseconds * 1000);
#elif __unix__
    usleep(milliseconds * 1000);
#elif __FreeBSD__
    usleep(milliseconds * 1000);
#else
    usleep(milliseconds * 1000);
#endif
}
int Common::GetLow()
{
    return _low;
}

int Common::GetHigh()
{
    return _high;
}

// Returns true if x is in range [low..high], else false
bool Common::InRange(int value)
{
    return value >= _low && value <= _high;
}

std::string Common::AnsiColor(int color)
{
    return "\033[38;5;" + std::to_string(color) + "m";
}

Common::~Common()
{
    std::cout << "Common Destructor!" << std::endl;
}
