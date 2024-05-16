
#include <array>
#include <cfloat>
#include <iostream>
#include <regex>
#include <stdint.h>
#include <string.h>
#include <string>

using namespace std;
using std::array;
using std::cin;
using std::cout;
using std::endl;

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
}

void Demo()
{
    printf("int convert to floating point bit array\n");
    // unsigned char bytes[4];
    // unsigned long n = 339319;

    // bytes[0] = (n >> 24) & 0xFF;
    // bytes[1] = (n >> 16) & 0xFF;
    // bytes[2] = (n >> 8) & 0xFF;
    // bytes[3] = n & 0xFF;

    // printf("( %lX ) => { `%X - %X - %X - %X` }\n%X", n, bytes[0], bytes[1], bytes[2], bytes[3], 0xFF);

    // int8_t data[4];
    // data[0] = 0x48;
    // data[1] = 0x65;
    // data[2] = 0x6c;
    // data[3] = 0x6f;
    // int x = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];

    // printf("\n%32X\n", x);

    // 3.14f 구조 해부.
    // sign - Exponent - Mantissa
    // 0    - 10000000 - 100 1000 11110101 11000010
    // 0                            : Sign bit (0: positive, 1: negative)
    // 1000 0000                    : Exponent (0x80 = 128, 128 - 127 = 1, 2^1 = 2)
    // 100 1000 1111 0101 1100 0010 : Mantissa normalized (23bit )

    /*

    1. 정수 `3.` 부분 이진후 만들기
    Divide the number repeatedly by 2.
    Keep track of each remainder.
    We stop when we get a quotient that is equal to zero.
    division = quotient + remainder;

        3 ÷ 2 = 1 + 1;
        1 ÷ 2 = 0 + 1
    --> 3(10) = 11(2)

    3. 소수 부분 이진만들기 (fractional part: `0.14`)

    - 2로 곱하면서 소수부분을 계속해서 추출한다.
    - 정수부분을 추출한다. (1 or 0)
    - 소수부분이 0이 되면 멈춘다.
        #) 곱하기 = 정수 (integer, 2) + 소수 (fractional part)
        1) 0.14 × 2 = 0 + 0.28;
        2) 0.28 × 2 = 0 + 0.56;
        3) 0.56 × 2 = 1 + 0.12;
        4) 0.12 × 2 = 0 + 0.24;
        5) 0.24 × 2 = 0 + 0.48;
        6) 0.48 × 2 = 0 + 0.96;
        7) 0.96 × 2 = 1 + 0.92;
        8) 0.92 × 2 = 1 + 0.84;
        9) 0.84 × 2 = 1 + 0.68;
        10) 0.68 × 2 = 1 + 0.36;
        11) 0.36 × 2 = 0 + 0.72;
        12) 0.72 × 2 = 1 + 0.44;
        13) 0.44 × 2 = 0 + 0.88;
        14) 0.88 × 2 = 1 + 0.76;
        15) 0.76 × 2 = 1 + 0.52;
        16) 0.52 × 2 = 1 + 0.04;
        17) 0.04 × 2 = 0 + 0.08;
        18) 0.08 × 2 = 0 + 0.16;
        19) 0.16 × 2 = 0 + 0.32;
        20) 0.32 × 2 = 0 + 0.64;
        21) 0.64 × 2 = 1 + 0.28;
        22) 0.28 × 2 = 0 + 0.56;
        23) 0.56 × 2 = 1 + 0.12;
        24) 0.12 × 2 = 0 + 0.24;

    ## 결론 ##
    --> 0.14(10) = 0.0010 0011 1101 0111 0000 1010(2)
    --> 3.14(10) = 11.0010 0011 1101 0111 0000 1010(2) * 2^0
    --> normalize = 1.10010 0011 1101 0111 0000 1010(2) * 2^1

    sign - Exponent           - Mantissa
    0    - 10000000           - 100 1000 11110101 11000010
    +    -   2^1 (128 - 127)  - 1. 은 항상 같으니까 제외하고 계산 10010 0011 1101 0111 0000 1010(2)

*/

    unsigned char buffer[4];
    buffer[0] = 0b01000000;
    buffer[1] = 0b01001000;
    buffer[2] = 0b11110101;
    buffer[3] = 0b11000010;
    union
    {
        float f;
        int i;
    } f;
    f.i = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];
    printf("Float=%f\n", f.f);

    // buffer[0] = 222, buffer[1] = 216, buffer[2] = 247, buffer[3] = 60;

    FloatToBinary(3.14);
    // 0b_01000000_01001000_11110101_11000010

    // loop();

    std::string str = "hello * my + name ^ is ..?.. vivakr.?";
    // escape (\\.) 하거나? 대괄호로 묶어서 처리해야 함.
    string s = regex_replace(str, regex("[.]"), "");
    string ss = regex_replace(str, regex("[?_*^]"), "");

    // 아래의 문자 자체를 지울 때는 escape 문자를 사용해야 한다.
    // ? : colou?r -> color or colour
    // * : 빵번 이상 -> ab*c -> ac, abc, abbc, abbbc, ...
    // + : 한번 이상 -> ab+c -> abc, abbc, abbbc, ...
    // . : 1개의 문자와 일치, 단일행 모드에서는 줄바꿈 문자 제외.
    // [ ] : 문자 클래스, [abc] -> a, b, c 중 하나와 일치.
    // [^ ] : 부정 문자 클래스, [^abc] -> a, b, c를 제외한 문자와 일치.
    // ^ : 문자열의 시작, ^abc -> abc로 시작하는 문자열과 일치.

    cout << s << endl
         << ss << endl;

    // 0000 0000 0000 0000 0000 0000 0000 0000     [ 32 bit (4bytes)]
    // 0100 1000                                   (data[0] << 24)
    //           0110 0101                         (data[1] << 16)
    //                     0110 1100               (data[2] << 8)
    //                               0110 1111     (data[3])
    //               `all or bitwise`
    // 0100 1000 0110 0101 0110 1100 0110 1111     [ result binary]
    //   4    8    6    5    6    C    6    F      ( result hex : 0x48656C6F )

    // 0000 0000, 0000 0101, 0010 1101, 0111 0111  (e.g., data)
    // 0000 0000, 0000 0000, 0000 0000, 1111 1111  (e.g., mask `FF`)
    //
    //                                  0000 0000 (data >> 24 )
    // 0000 0000, 0000 0000, 0000 0000, 1111 1111 ( & mask)
    //                                          0 ( 0 )

    //                       0000 0000, 0000 0101 (data >> 16 )
    // 0000 0000, 0000 0000, 0000 0000, 1111 1111 ( & mask)
    //                                       0101 (5)

    //            0000 0000, 0000 0101, 0010 1101 ( data >> 8)
    // 0000 0000, 0000 0000, 0000 0000, 1111 1111 ( & mask)
    //                                  0010 1101 (2D)

    // 0000 0000, 0000 0101, 0010 1101, 0111 0111 (data)
    // 0000 0000, 0000 0000, 0000 0000, 1111 1111 ( & mask)
    //                                  0111 0111 (77)

    // --> 5 2D 77
}

void DemoB()
{
    int a{123};

    int arr[5]{};

    for (auto &at : arr) {
        cout << at;
    }
    cout << endl;
    auto x{3};
    cout << typeid(x).name() << endl;
}

void ArrayDemo()
{
    int arr[5] = {1, 2, 3, 4, 5};

    array<int, 5> array = {1, 2, 3, 4, 5};
    for (auto i = 0; i < array.size(); i++) {
        cout << array[i] << endl;
    }

    // 이더레이터 : begin()  ~ end()
    for (auto it = array.begin(); it != array.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}

void DemoC()
{
}
int main(int argc, char *argv[])
{

    ArrayDemo();

    return 0;
}
