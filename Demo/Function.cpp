#include <iostream>

using namespace std;

// function = a block of reusable code
// return = return a value back to the spot
//          where you called the encompassing function
// 함수를 호출한 지점으로 다시 값을 반환합니다.

void HappyBirthday(std::string name, int age);
double Square(double length);
double Cube(double length);
string ConcatStrings(string firstname, string lastname);
void BakePizza();
void BakePizza(string topping);
void BakePizza(string topping1, string topping2);
void GolbalFunc();

// 전역변수
// 전역 네임스페이스를 오염시키므로 가급 사용하지 말아야 함
int var = 3;

void MainFunction() {

    // local variables
    std::string name = "Viv";
    int age = 21;
    HappyBirthday(name, age);

    // 넓이 구하기
    // 넓이 구하기
    double length = 6.0;
    std::cout << "한변의 길이가 " << length << " 인 면의 넓이는 " << Square(length) << std::endl;
    cout << "한 변의 길이가 " << length << " 인 육각형의 부피는 " << Cube(length) << endl;

    string firstName = "장";
    string lastName = "길산";
    cout << "당신의 이름은 " << ConcatStrings(firstName, lastName) << endl;

    string topping1 = "peperoni";
    string topping2 = "mushrooms";

    BakePizza();
    BakePizza(topping1);
    BakePizza(topping1, topping2);

    // Call Global Variable Used Function
    // 로컬과 전역변수가 동일 할때는 로컬 우선하나 
    // 전역변수를 사용할 시에는 앞에 `::` 콜론 두개를 붙임
    int var = 111;
    cout << "로컬: " << var << ", 전역: " << ::var << endl;
    GolbalFunc();
}

void HappyBirthday(std::string name, int age) {

    // 컴파일러 c++20 테스트
    auto result = (10 <=> 20) > 0;
    if (result == 0) {
        cout << "You C++ Compiler is C++-20, 23 Enable" << endl;
    } else {
        cout << "You C++ Compiler is C++-20, 23 UnEnable" << endl;
    }

    std::cout << endl;
    std::cout << "Happy Birthday to you! " << name << std::endl;
    std::cout << "You are " << age << " years old!" << std::endl;
}

double Square(double length) { return length * length; }
double Cube(double length) { return length * length * length; }
string ConcatStrings(string firstName, string lastName) { return firstName + " " + lastName; }

// 오버로딩 (overloading) 견본
void BakePizza() { cout << "Here is your pizza!" << endl; }
void BakePizza(string topping) { cout << "Here is your " << topping << " pizza!" << endl; }
void BakePizza(string topping1, string topping2) {
    cout << "Here is your " << topping1 << " and " << topping2 << " pizza!" << endl;
}

// Global Variable Used Function
void GolbalFunc() {
    int var = 222;
    cout << "로컬: " << var << ", 전역: " << ::var << endl;
}
