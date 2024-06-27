#include <iostream>

using namespace std;

void Walk(int steps);
long Factorial(int num);

/// @brief ref Bro Code
void Recursion() {
    // Recusion
    // A programmin technique where a function invokes itself form within
    // break a complex concept into a repeatable single step

    // (iterative vs recursiv)
    // Advantages : less code and is cleaner useful for sorting and searching algorithms
    // disadvantages : Uses more memory slower

    Walk(100);

    long fv = Factorial(10);
    cout << "5 Factorial : " << fv << endl;
}

void Walk(int steps) {
    if (steps > 0) {
        cout << steps << ". You take a step!\n";
        Walk(steps - 1);
    }
    // for (int i = 0; i < steps; i++)
    // {
    //     cout << i + 1 << ". You take a step!\n";
    // }
}

// Recursion
long Factorial(int num) {

    if (num == 1) return 1;
    return num * Factorial(num - 1);

    // 일반적인 반복계산
    // long result;
    // for (int i = 1; i <= num; i++)
    // {
    //     result *= i;
    // }
}

