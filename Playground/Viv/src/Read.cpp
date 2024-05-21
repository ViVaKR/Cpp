#include "../include/io.hpp"
#include <fstream>
#include <iostream>

void ReadWrite::ReadFile()
{
    std::ifstream file(Path);
    if (file.is_open()) {
        std::string str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        cout << str << endl;
    } else {
        cout << "File not found" << endl;
    }
    file.close();
}
