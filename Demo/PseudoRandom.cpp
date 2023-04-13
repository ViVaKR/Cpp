#include <iostream>
using namespace std;

void PseudoRandom()
{
    // pseudo-random = NOT truly random (but close)
    
    srand(time(NULL));
    
    int num = rand();
    
    std::cout << "Random Number: " << num << endl;
}
