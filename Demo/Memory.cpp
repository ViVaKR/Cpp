#include <iostream>

using namespace std;

void SwapByValue(string x, string y);
void SwapByRef(string &x, string &y);

/// @brief
void Memory() {

    string name = "Viv";
    int age = 21;
    bool student = true;

    cout << &name << endl;    //-> Hex Decimal (0x7ffeeedc0350)
    cout << &age << endl;     //-> Hex Decimal (0x7ffee946234c)
    cout << &student << endl; //-> Hex Decimal (0x7ffee946234b)

    string x = "Koo";
    string y = "Water";

    SwapByValue(x, y);
    cout << "Pass by Value" << endl;
    cout << "x = " << x << "\ny = " << y << endl;

    std::cout << endl;

    SwapByRef(x, y);
    cout << "Pass By Reference" << endl;
    cout << "x = " << x << "\ny = " << y << endl;
}

// Copy Value : Pass by value
void SwapByValue(string x, string y) {
    string temp = x;
    x = y;
    y = temp;
}

// Ref Value : Pass by Reference
void SwapByRef(string &x, string &y) {
    string temp = x;
    x = y;
    y = temp;
}
