#include <iostream>

using namespace std;

void SwapByValue(string x, string y);
void SwapByRef(string &x, string &y);
void PrintInfo(const string name, const int age);
int GetDigit(const int number);
int SumOddDigits(const string cardNumber);
int SumEvenDigits(const string cardNumber);

/// @brief
void Memory() {

    // Memory Address :
    // A location in memory where data is stored
    // A memory address can accessed with `&` (address-of operator)

    string name = "Viv";
    int age = 21;
    bool student = true;

    cout << &name << endl;    //-> Hex Decimal (0x7ffeeedc0350)
    cout << &age << endl;     //-> Hex Decimal (0x7ffee946234c)
    cout << &student << endl; //-> Hex Decimal (0x7ffee946234b)

    string x = "Koo";
    string y = "Water";

    std::cout << endl;

    SwapByValue(x, y);
    cout << "Pass by Value" << endl;
    cout << "x = " << x << " " << &x << "\ny = " << y << " " << &y << endl;

    std::cout << endl;

    SwapByRef(x, y);
    cout << "Pass By Reference" << endl;
    cout << "x = " << x << " " << &x << "\ny = " << y << " " << &y << endl;

    // Const Parameter :
    // Parameter that is effectively read-only code is more
    // secure & conveys intent useful for references and pointers
    string nm = "Viv";
    int ag = 35;
    PrintInfo(nm, ag);

    // Card Card Number Check Validation
    string cardNumber;
    int result = 0;
    cout << "Enter a credit card #: ";
    cin >> cardNumber;
    result = SumEvenDigits(cardNumber) + SumOddDigits(cardNumber);

    if (result % 10 == 0) {
        cout << cardNumber << " is valid";
    } else {
        cout << cardNumber << " is not valid";
    }
}

// Copy Value : Pass by value
void SwapByValue(string x, string y) {

    cout << "x = " << x << " " << &x << endl;
    cout << "y = " << y << " " << &y << endl;
    string temp = x;
    x = y;
    y = temp;
}

// Ref Value : Pass by Reference
void SwapByRef(string &x, string &y) {
    cout << "x = " << x << " " << &x << endl;
    cout << "y = " << y << " " << &y << endl;
    string temp = x;
    x = y;
    y = temp;
}

void PrintInfo(const string name, const int age) {
    cout << name << endl;
    cout << age << endl;
}

int GetDigit(const int number) {
    // 18   8       18 /10  -> 1 % 10 -> 1 -> 9
    return number % 10 + (number / 10 % 10);
}
int SumOddDigits(const string cardNumber) {

    int sum = 0;

    for (int i = cardNumber.size() - 1; i >= 0; i -= 2) {
        sum += cardNumber[i] - '0';
    }
    // ascii
    // 48 - 0
    // 57 - 9

    return 0;
}
int SumEvenDigits(const string cardNumber) {

    int sum = 0;

    for (int i = cardNumber.size() - 2; i >= 0; i -= 2) {
        sum += GetDigit((cardNumber[i] - '0') * 2);
    }
    // ascii
    // 48 - 0
    // 57 - 9

    return 0;
}
