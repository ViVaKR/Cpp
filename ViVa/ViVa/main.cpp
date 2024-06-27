#include <iostream>
#include <algorithm>
#include "Sources/PlayGround.hpp"
using namespace std;

template <typename T>
int Adder(T a, T b) {
    return a + b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    TemplateEx<int> t_int(12, 45);
    t_int.SetA(50);
    t_int.SetB(40);
    int sum = t_int.Add();
    cout << "A = " << t_int.GetA() << endl;
    cout << "B = " << t_int.GetB() << endl;
    
    
    auto x = { 1, 2, 3};
    
    cout << " " << sum << ", tempate: " << Adder(27, 13) << endl;

    return 0;
}
