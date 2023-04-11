#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Calculate() {
    
    char op;
    double num1;
    double num2;
    double result;
    
    std::cout << "************** CALCULATOR **************" << std::endl;
    
    std::cout << "다음중 하나를 입력하세요 (+ - * /) >> ";
    std::cin >> op;
    
    std::cout << "Enter #1 >> ";
    std::cin >> num1;
    
    std::cout << "Enter #2 >> ";
    std::cin >> num2;
    
    switch (op) {
        case '+':result = num1 + num2;break;
        case '-':result = num1 - num2;break;
        case '*':result = num1 * num2;break;
        case '/':result = num1 / num2;break;
        default: result = 0;break;
    }
    std::cout << num1 << " " << op << " " << num2 << " = " << result << std::endl;
    std::cout << "****************************************" << std::endl;
    std::cout << "\n";
}
