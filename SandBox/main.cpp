
#include <array>
#include <cfloat>

#include <algorithm>
#include <bitset>
#include <iostream>
#include <numeric>
#include <regex>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

using namespace std;
using std::array;
using std::cin;
using std::cout;
using std::endl;
using std::initializer_list;

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
    auto x{3};          // int
    auto y = {1, 2, 3}; // initializer_list<int>
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

void Menu();

int main(int argc, char *argv[])
{
    int choice(0);
    if (argc >= 2) choice = stoi(argv[1]);

    while (true) {
        switch (choice) {
            case 0: exit(0);
            case 1: Array(); break;         // [ 배열 ]
            case 2: NewInitialize(); break; // [ 새로운 초기화 규칙 ]
            case 3:
                FloatToBinary(3.14);
                break;                      // [ 실수를 2진수로 변환 ]
            // case 4 : StandardDeviation(vector<int>{1, 2}); break; // [ 표준편차 ]
            default: exit(55); break;
        }

        cout << endl
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
    cout << "5. ..." << endl;
}
