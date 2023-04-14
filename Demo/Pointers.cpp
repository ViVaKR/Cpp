#include <iostream>

using namespace std;

void Pointers() {

    // Pointers = variable that stores a memory address of another variable
    // sometimes it's easier to work with an address

    // & -> Address of operator (주소 연산자)
    // * -> dereference operator (역참조 연산자)

    string name = "Viv";
    string *pName = &name;
    cout << pName << endl;  // -> 0x7ffeecf86350
    cout << *pName << endl; // -> Viv

    int age = 21;
    int *pAge = &age;
    cout << pAge << endl;  // -> 0x7ffee953b33c
    cout << *pAge << endl; // -> 21

    string strArr[5] = {"p1", "p2", "p3", "p4", "p5"};
    string *pStrArr = strArr; // 배열 이름은 자체가 Address 임으로 주소연산자 불필요

    // 배열 포인터
    cout << "pStrArr = " << pStrArr << endl << "pStrArr[1] = " << pStrArr[1] << endl;
    cout << "*pStrArr = " << *pStrArr<< endl; // 배열 첫번째 인덱스의 값
    cout << "strArr[0] = " << strArr[0] << endl;

    // Null value : 
    // A special value that means simething has no value.
    // When a pointer is holding a null value, that pointer  is not pointing at anything (null pointer)
    // nullptr = keyword represents a null pointer literal
    // nullptrs are helpful when determining if an address was successfully assigned to a pointer

}
