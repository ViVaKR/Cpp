#include <iomanip>
#include <iostream>

using namespace std;

void ShowBalance(double balance);
double WithDraw(double balance);
double Deposit();

void Banking() {

    double balance = 0;
    int choice = 0;

    do {
        cout << "*****************\n";
        cout << "Enter your choice\n";
        cout << "*****************\n";
        std::cout << "1. 예금잔액 (Show Balance)\n";
        std::cout << "2. 예금하기 (Deposit Money)\n";
        std::cout << "3. 예금인출 (Withdraw Money)\n";
        std::cout << "4. 업무종료 (Exit)\n";
        std::cout << endl;
        cout << ">>> ";
        std::cin >> choice;
        
        // 오류플래그를 초기화
        std::cin.clear(); 
        
        // 입력버퍼를 지움, 엔터키를 누르면 줄바꿈 문자가 있고, 입력 버퍼이므로 플러시만 하면됨
        fflush(stdin); 
        
        std::cout << endl;

        switch (choice) {
            case 1: ShowBalance(balance); break;
            case 2: ShowBalance(balance += Deposit()); break;
            case 3: ShowBalance(balance -= WithDraw(balance)); break;
            case 4: cout << "저희 은행을 이용하여 주셔서 감사합니다!\n"; break;
            default: cout << "잘못된 선택입니다!\n"; break;
        }
        std::cout << endl;
    } while (choice != 4);
}

void ShowBalance(double balance) {

    std::cout << "Your Balance is $" << std::setprecision(2) << std::fixed << balance << std::endl;
}

double Deposit() {

    double amount = 0;
    std::cout << "Enter amount to be deposited: ";
    std::cin >> amount;

    if (amount > 0)
        return amount;
    else
        std::cout << "That's not a valid amount: \n";
    return 0;
}

double WithDraw(double balance) {

    cout << "balance = " << balance << endl;
    double amount = 0;
    cout << "Enter amount to be withdraw: ";
    std::cin >> amount;

    if (amount > balance) {
        cout << "Insuffictient funds" << endl;
        return 0;
    } else if (amount < 0) {
        cout << "That's not a valied amount" << endl;
    } else {
        return amount;
    }

    return balance;
}
