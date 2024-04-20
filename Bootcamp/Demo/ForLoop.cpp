#include <iostream>
using namespace std;

void ForLoop()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
    }
    std::cout << " HAPPY NEW YEAR! " << endl;

    cout << endl;

    // break = break out of a loop
    // continue = skip current iteration
    for (int i = 30; i >= 0; i--)
    {
        if (i == 27)
            continue;
        if (i == 23)
            break;

        cout << i << endl;
    }
    std::cout << " Hello World! " << endl;

    // 중첩 반복문
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            std::cout << i << ": " << j << ", ";
        }

        cout << endl;
    }

    int rows;
    int columns;
    char symbol;

    std::cout << "How many rows?: ";
    std::cin >> rows;
    
    std::cout << "How many colums?: ";
    std::cin >> columns;
    
    std::cout << "Enter a symbol to use: ";
    std::cin >> symbol;
    std:cout << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << symbol << " ";
        }
        cout << endl;
    }
}
