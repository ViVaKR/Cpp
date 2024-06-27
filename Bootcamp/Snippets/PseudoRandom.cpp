#include <ctime>
#include <iostream>

using namespace std;

void PseudoRandom()
{
    // pseudo-random = NOT truly random (but close)

    srand(time(NULL));

    int num1 = (rand() % 6) + 1; // 1 ~ 6 주사위
    int num2 = (rand() % 6) + 1; // 1 ~ 6 주사위
    int num3 = (rand() % 6) + 1; // 1 ~ 6 주사위

    std::cout << "Random Numbers: \n"
              << "- 1번 주사위: " << num1 << endl
              << "- 2번 주사위: " << num2 << endl
              << "- 3번 주사위: " << num3 << endl;

    std::cout << endl;
    std::cout << endl;

    srand(time(0));
    int rnum = rand() % 5 + 1;
    std::cout << "- You Choice Number: " << rnum << std::endl;
    std::cout << endl;

    switch (rnum)
    {
        case 1: cout << " - You win a bumper sticer!" << endl; break;
        case 2: cout << " - You win a t - shirt !" << endl; break;
        case 3: cout << " - You win a free lunch !" << endl; break;
        case 4: cout << " - You win a gift card !" << endl; break;
        case 5: cout << " - You win a concert ticket !" << endl; break;
    }

    std::cout << "***** Start Game Guess Number *****" << std::endl;

    int num;
    int guess;
    int tries;

    srand(time(NULL));
    num = (rand() % 100) + 1;

    std::cout << "***** NUMBER GUESSING GAME *****\n";

    do
    {
        std::cout << "Enter a guess between (1-100) >>> ";
        std::cin >> guess;

        tries++;
        if (guess > num)
        {
            std::cout << "Too high! => " << guess << std::endl;
        }
        else if (guess < num)
        {
            std::cout << "Too low! => " << guess << std::endl;
        }
        else
        {
            std::cout << "CORRECT! You Win!!! # of tries  " << tries << ", " << num << std::endl;
        }
        std::cout << "************************************" << std::endl;

    } while (guess != num);
}
