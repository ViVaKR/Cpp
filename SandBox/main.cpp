#include "./headers/StackEx.h"
#include <algorithm>
#include <array>
#include <bitset>
#include <cfloat>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <numeric>
#include <regex>
#include <streambuf>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

void FloatToBinary(float num)
{
    int exp, sign;
    float mantissa = frexpf(num, &exp); // 가수부와 지수부 계산
    if (num < 0) {
        sign = 1;                       // 음수 처리
        mantissa = -mantissa;
    } else {
        sign = 0;                       // 양수 처리
    }
    printf("실수 값 %f의 2진수 표현: %d ", num, sign);
    for (int i = FLT_MANT_DIG - 1; i >= 0; i--) {
        mantissa *= 2;
        if (mantissa >= 1) {
            printf("1");
            mantissa -= 1;
        } else {
            printf("0");
        }
    }

    printf(" x 2^%d\n", exp - 1);

    cout << "\n";
    int bias = (exp - 1) + 127; // 지수부 계산
    std::string binary = std::bitset<8>(bias).to_string();
    cout << binary << endl;

    unsigned long decimal = std::bitset<8>(binary).to_ulong();
    cout << decimal << endl;
    cout << "\n";

    union
    {
        float input; // assumes sizeof(float) == sizeof(int)
        int output;
    } data;

    data.input = num;

    std::bitset<sizeof(float) * CHAR_BIT> bits(data.output);
    std::cout << bits << std::endl;

    // or
    std::cout << "BIT 4: " << bits[4] << std::endl;
    std::cout << "BIT 7: " << bits[7] << std::endl;
}

/// @brief 새로운 초기화
void NewInitialize()
{
    int a = 1;
    int b(3);
    int c = {3};

    int d{3};
    int e{0};
    int f{};
    cout << a << b << c << d << e << f << endl;

    int arr[5]{}; // 0으로 초기화
    for (auto &item : arr) {
        cout << item << " ";
    }

    cout << "\n";

    // auto : 자동으로 타입을 추론, 초기화 값에 따라 타입이 결정된다. type inference
    auto x{3}; // int

    auto y = {1, 2, 3};

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
}

/// @brief 표준편차
void StandardDeviation(vector<int> v)
{
    /*
        1. 평균을 구한다.
        2. 편차를 구한다.
        3. 편차의 제곱을 구한다.
        4. 편차 제곱의 평균으로 분산을 구한다. (편차제곱의 평균)
        5. 분산에 루트를 씌워 표준편차를 구한다.
     */

    double sum = std::accumulate(v.begin(), v.end(), 0.0);
    double mean = sum / v.size();

    std::vector<double> diff(v.size());
    std::transform(v.begin(), v.end(), diff.begin(), [mean](double x) { return x - mean; });
    double sq_sum = std::inner_product(diff.begin(), diff.end(), diff.begin(), 0.0);
    double stdev = std::sqrt(sq_sum / v.size());

    cout.precision(3);
    // 평균 : 전체 합을 원소의 개수로 나눈 값
    cout << "\u27A5 평균\t:\t" << mean << endl;
    // 분산 : 편차들의 제곱의 평균 (평균에서 얼마나 떨어져 있는지)
    cout << "\u27A5 분산\t:\t" << (sq_sum / v.size()) << endl;
    // 표준편차 : 평균에서 얼마나 떨어져 있는지
    cout << "\u27A5 표준편차:\t" << stdev << endl;
    cout << "\n";
}

/// @brief 배열
void Array()
{
    // int arr[5] = {1, 2, 3, 4, 5};        // type 1
    // array<int, 5> arr = {1, 2, 3, 4, 5}; // type 2
    // 범위 기반 for문
    // for (auto i = 0; i < arr.size(); i++) {
    //     cout << arr[i] << endl;
    // }

    // 이더레이터 : begin(시작원소)  ~ end(마지막 원소 다음 위치)
    // for (auto it = arr.begin(); it != arr.end(); it++) { // it : 이터레이터
    //     cout << *it << " ";                              // *it : 이터레이터가 가리키는 원소
    // }
    // cout << "\n";
    // for (auto &item : arr) {
    //     cout << item << " ";
    // }
    // cout << endl;

    const int SIZE = 4;
    array<int, SIZE> studentId = {};
    array<string, SIZE> studentName = {};

    cout << "\u27A6 학생 정보를  \u275D\033[33m학번 \u2615 이름\033[0m\u275E\n방식을 입력하세요(아래 명단 참조)\n";
    cout << "1001 장길산, 1002 임꺽정 1003 최경희 1004 용감이\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "\033[31m\u26DF\033[0m  ";
        cin >> studentId[i] >> studentName[i];
    }
    cout << "\n";
    cout << "\t\033[31;42m" << std::string(5, (char)0x20) << "\u2728 학생정보 \u2728" << std::string(5, (char)0x20) << "\033[0m" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\t" << i + 1 << "\t" << studentId[i] << "\t" << studentName[i] << endl;
    }
    cout << "\n";
    array<string, 4> className = {"대학수학", "대학영어", "C++언어", "테니스"};
    vector<vector<int>> classGrade = {{91, 83, 95, 88}, {78, 85, 92, 89}, {67, 90, 77, 83}, {47, 88, 96, 85}};

    for (auto i = 0; i < classGrade.size(); i++) {
        cout << "\033[33m";
        cout << "\u2728 [ " << className[i] << " ] 점수, 평균, 분산과 표준편차 \u2728\n";
        cout << "\033[35m\u2748 Score :\t";
        for (auto &item : classGrade[i]) {
            cout << item << " ";
        }
        cout << "\033[0m\n";
        StandardDeviation(classGrade[i]);
    }
}

void Func(int n)
{
    cout << n << ", ";
}

struct PrintFunc
{
    void operator()(int n) { cout << n << ", "; }
};

int global = 100;
/// @brief 람다식
void Lambda()
{
    // 람다식 : 익명함수, 함수를 정의하고 호출하는 것을 동시에 할 수 있다.
    // [캡쳐 블록](매개변수) -> 반환형 {함수 본문}
    // 캡쳐 블록 : 외부 변수를 람다식 내부로 가져오는 것
    // [=] : 외부 변수를 모두 가져온다.
    // [&] : 외부 변수를 모두 참조한다.
    // [x] : x만 가져온다.
    // [&x] : x만 참조한다.
    // [=, &x] : 외부 변수는 모두 가져오고, x만 참조한다.
    // [&, x] : 외부 변수는 모두 참조하고, x만 가져온다.
    // [this] : 클래스 내부의 멤버 변수를 사용할 때 사용한다.
    // [&, this] : 클래스 내부의 멤버 변수를 참조할 때 사용한다.

    /*** [ captures ] (params) { body } ***/

    // 람다식을 변수에 저장
    auto f = [](int a, int b) -> int { return a + b; };
    cout << f(1, 2) << endl;

    // 람다식을 함수의 인자로 사용
    auto g = [](int a, int b) -> int { return a * b; };
    cout << g(2, 3) << endl;

    // 람다식을 함수의 반환값으로 사용
    auto h = [](int a, int b) -> int { return a - b; };
    cout << h(3, 2) << endl;

    // 람다식을 함수의 반환값으로 사용
    auto i = [](int a, int b) -> int { return a / b; };
    cout << i(6, 2) << endl;

    // 람다식을 함수의 반환값으로 사용
    auto j = [](int a, int b) -> int { return a % b; };
    cout << j(5, 2) << endl;

    std::vector<int> v{1, 2, 3, 4, 5};
    for (auto &item : v) {
        cout << item << ", ";
    }
    cout << endl;

    // 람다식을 함수의 인자로 사용
    std::for_each(v.begin(), v.end(), [](int n) { cout << n << " "; });
    cout << endl;
    std::for_each(begin(v), end(v), [](int n) { cout << n << " - "; });
    cout << "\n";
    std::for_each(v.begin(), v.end(), Func);
    cout << "\n\n";

    int id;
    string name;
    cout << "학번과 이름을 입력하세요:\n\u27A5 ";
    cin >> id >> name;
    int a;
    int b;
    cout << "삼각형의 밑변과 높이를 입력하세요:\n\u27A5 ";
    cin >> a >> b;
    auto k = [a, b](bool tf) -> int { return tf ? a * b / 2 : a * b; };
    cout << "학번 " << id << ", 이름 " << name << endl;
    cout << "밑변 " << a << ", 높이 " << b << " 인 삼각형의 넓이는 " << k(true) << " 입니다." << endl;
    cout << "밑변 " << a << ", 높이 " << b << " 인 사각형의 넓이는 " << k(false) << " 입니다." << endl;

    std::for_each(v.begin(), v.end(), PrintFunc());
    cout << "\n";
    auto print_v = [](int n) { if(n%2 == 0) cout << n << " "; };
    auto predicate = [](int n) -> bool { return n % 2 == 0; };
    std::for_each(v.begin(), v.end(), [predicate](int n) { if(predicate(n)) cout << n << " "; });
    cout << "\n";
    int lastResult = -1;
    auto last = [&lastResult](int n) { lastResult = n; cout << n << ", "; };

    std::for_each(v.begin(), v.end(), last);
    cout << "\n";
    cout << "Last Result: " << lastResult << endl;
    cout << "\n";

    // Chapter 2 : Capturing Variables
    int ref = -1;
    int ref2 = -1;

    // 복사본을 전달하므로 읽기 전용을 변경가능하게 하려면 mutable 사용하나
    // 스코프를 벗어 나면 변경된 값이 사라지므로, 참조로 전달하는 것이 좋다.
    // mutable : 외부 변수를 변경할 수 있도록 한다. or `&` 사용
    // auto pr = [ref, ref2](int n) mutable { // -1
    // auto pr = [=](int n) mutable { // 값으로 전달, 위와 동일한 결과 -1
    auto pr = [&](int n) { // 참조로 전달
        ref = n;
        ref2 = n;
        cout << n << ",";
    };

    cout << endl
         << ref << endl;
    cout << ref2 << endl;

    // With Global Variables : 전역변수(정적 포함)는 참조로 전달하지 않아도 된다.
    auto pr2 = [=](int n) {
        global = n;
        cout << n << ",";
    };

    cout << endl
         << "Global: "
         << global << endl;
}

void Menu();

int main(int argc, char *argv[])
{
    int choice(0);
    if (argc >= 2) choice = std::stoi(argv[1]);

    while (true) {
        switch (choice) {
            case 0: {
                system("clear");
                exit(0);
            }
            case 1: Array(); break;         // [ 배열 ]
            case 2: NewInitialize(); break; // [ 새로운 초기화 규칙 ]
            case 3:
                FloatToBinary(3.14);
                break;                      // [ 실수를 2진수로 변환 ]

            case 4: {
                // TODO
                Array();
            }; break;                // [ 표준편차 ] Use initializer list without explicitly creating a vector
            case 5: Lambda(); break; // [ 람다식 ]
            case 6: {
                // TODO
            }; break;             // [ 연산자 오버로딩 ]
            case 7: {
                cout << "템플릿" << endl;
            } break;              // [ 템플릿 ]
            case 8: {
                cout << "*** 스택 ***" << endl;
                StackEx stack(5); // 스택 객체 생성
                while (true) {
                    cout << "\n\t\t *** 스택 ***\n";
                    cout << "1. Push\t2. Pop\t3. Print\t4. Clear\\t5. Exit\n";
                    cout << "Enter your choice: ";
                    int choice;
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            int data;
                            cout << "Enter data: ";
                            cin >> data;
                            stack.push(data);
                            stack.PrintStack();
                        } break;
                        case 2: {
                            int data = stack.pop();
                            if (data != -1) {
                                cout << "Popped data: " << data << endl;
                            }
                            stack.PrintStack();
                        } break;
                        case 3: {
                            stack.PrintStack();
                        } break;
                        case 4: {
                            stack.Clear();
                            stack.PrintStack();
                        } break;
                        case 5: {
                            exit(0);
                        } break;
                        default: {
                            cout << "Invalid choice" << endl;
                        } break;
                    }
                }
            } break; // [ 스택 ]
            case 9: {
                int a;
                cout << "Enter a number: ";
                cin >> a;
                cout << "The number is: " << a << endl;
            } break;
            default: exit(55); break;
        }

        cout << endl
             << endl
             << "\u2728 \033[33m실행 메뉴 선택\033[0m \u2728"
             << "\n";
        Menu();
        cout << "\n";
        cout << "\033[33m\u269E Enter your choice \u269F\033[0m"
             << endl
             << "\033[31m\u2771\033[0m ";
        cin >> choice;
    }
    return 0;
}

void Menu()
{
    cout << "0. Exit" << endl;
    cout << "1. Array" << endl;
    cout << "2. New Initialize" << endl;
    cout << "3. FloatToBinary" << endl;
    cout << "4. 표준편차" << endl;
    cout << "5. 람다식" << endl;
    cout << "6. 연산자 오버로딩" << endl;
}
