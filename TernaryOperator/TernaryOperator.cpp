#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void TernaryOperator(){
    
    // ternary operator ?:= replacement to an if/else statement
    // dondition ? expression1 : expression2;
    
    // type 1
    int grade = 75;
    if (grade >=60) {
        cout << "You pass! (1)";
    }else{
        cout << "You fail! (1)";
    }
    cout << endl;
    
    // type 2
    grade >=60 ? cout << "You pass! (2)" : cout << "You fail! (2)";
    cout << endl;
    
    // type 3
    cout << ((grade >=60) ? "You pass! (3)" : "You fail! (3)");
    cout << endl;
    
    cout << "Enter Number >> ";
    
    int number;
    cin >> number;
    number % 2 == 1 ? cout << number << " is ODD (홀수)" : cout << number << " is EVEN (짝수)";
    cout << endl;
}
