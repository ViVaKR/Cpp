#include <iostream>

using namespace std;

int Fibonacci(int number);
static int temp[30] = {0};

/// @brief 트리거
void Caller() {
    system("clear");
    int number;
    cout << "피보할 숫자를 넣으세요 (30이하) >> ";
    cin >> number;
    long result = Fibonacci(number);
    std::cout << endl;

    if (number > 30)
    {
        cout << "30이하의 숫자를 넣으세요.. ";
        return;
    }

    cout << number << " 의 피보는 = " << result << endl;
    std::cout << endl;
}

/// @brief 피보나치 수열
/// @param number 30이하
/// @return 결과
int Fibonacci(int number) {
    if (number == 0) return temp[0] = 0;
    if (number == 1) return temp[1] = 1;
    if (temp[number] > 0)return temp[number]; // 스택 빼내기 시간

    // 스택에 차곡이 쌓기
    return temp[number] = Fibonacci(number - 1) + Fibonacci(number - 2);
}
