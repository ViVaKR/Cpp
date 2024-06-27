#include <iostream>

void DoWhileLoop()
{
    // do while loop =  do some block of code first,
    //                  THEN repeat again condition is true;

    int number; // 값을 할당하지 않으면 -> 0
    std::cout << number << std::endl; // rs -> 0
    std::cin.ignore();

    // 0 이 0보다 작지 않으므로 거짓으로
    // while loop 를 시작도 하지 않는 문제가 발생함
    while (number < 0) 
    {
        std::cout << "Enter a positive #: ";
        std::cin >> number;
    }
    std::cout << "The While Loop # is: " << number << std::endl;
    
    std::cout << "== Do While Loop Exampe ==\n";
    do
    {
        std::cout << "양수를 입력하세요 #: ";
        std::cin >> number;
    } while (number < 0);
    
    std::cout << "The Do While Loop # is: " << number << std::endl;
}
