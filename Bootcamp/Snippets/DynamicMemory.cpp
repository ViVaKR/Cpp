#include <iostream>

using namespace std;

/// @brief Ref Bro Code
void DynamicMemory() {

    // ( Dynamic Memory )
    // Memory that is allocated after the program is already comiled & running.
    // Use the 'new' operator to allocate memory in the heap rather than the stack
    // Useful when we don't know how much memory we will need.
    // Makes our programs more flexible, especially when accepting user input.
    // 프로그램이 이미 컴파일되어 실행된 후에 할당되는 메모리.
    // 'new' 연산자를 사용하여 스택이 아닌 힙에 메모리를 할당합니다.
    // 얼마나 많은 메모리가 필요할 지 모를 때 유용합니다.
    // 특히 사용자 입력을 받아들일 때 프로그램을 더 유연하게 만듭니다.

    // (Memory)
    // Heap
    // Stack
    // Global / Static
    // Text (code)

    int *pNum = NULL;
    pNum = new int; // within pnum because it's a pointer it's Pointing to a memory location
    *pNum = 21;
    cout << "Address : " << pNum << endl; // 0x7fd276c05b00, Heap Memory
    cout << "Value: " << *pNum << endl;   // 21
    delete pNum; // freeing up the memory

    char *pGrades = NULL;
    int size;

    cout << "How many grades to enter in?: ";
    cin >> size;
    pGrades = new char[size];
    cout << "Checking ~~\n";
    for (int i = 0; i < size; i++) 
    {
        cout << "Enter grade #" << i + 1 << ": ";
        cin >> pGrades[i];
    }

    for (int i = 0; i < size; i++) 
    {
        cout << pGrades[i] << " ";
    }
    std::cout << endl;

    delete[] pGrades;

}
