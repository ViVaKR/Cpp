#include "../include/io.hpp"
#include <fstream>
#include <iostream>

void ReadWrite::WriteFile()
{
    cout << "WriteFile" << endl;

    std::ofstream outputFile(Path);
    if (outputFile.is_open()) {
        outputFile << "Hello, World!\n";
        outputFile << "Hi, Everyone!\n";
        outputFile << "Fine Thanks And You?\n";
        cout << "\033[31m*** File written successfully! ***\033[0m" << endl;
        cout << "\u2761 path: " << Path << endl;
    } else {
        cout << "File not found! Create new" << endl;
        // outputFile.open(path, fstream::app);
        outputFile << "Create new file and write!\n";
    }
    outputFile.close();
}
