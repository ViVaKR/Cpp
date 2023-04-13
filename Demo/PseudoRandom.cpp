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
}
