#include <iostream>

using namespace std;

// Generic Types (일반형)
template <typename T,  typename U>

auto Max(T x, U y) { return (x > y) ? x : y; } // 유연한 반환 타입
// T Max(T x, U y) { return (x > y) ? x : y; } // 고정된 반환 타입

/// @brief Ref. Bro Code
void FuncTemplate() {
    
    // function template
    // describes what a function looks like.
    // Can be used to generate as many overloaded functions each using different data types
    cout << Max(345, 843) << endl;
    cout << Max(3.14, 1.55) << endl;
    cout << Max('A', 'B') << endl;
    cout << Max(3.14, 45) << endl; // Hello 서로다른 타입
}
