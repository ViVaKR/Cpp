#include "../include/io.hpp"
#include <fstream>
#include <iostream>

void ReadWrite::ReadFile()
{
    std::ifstream file(Path);
    std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    cout << str << endl;
}
