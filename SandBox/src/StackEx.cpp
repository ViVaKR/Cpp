#include "../headers/StackEx.h"
#include <iostream>
using namespace std;
using std::cout;
using std::endl;

StackEx::StackEx(int size)
{
    stack = new int[size];
    top = -1;
    this->size = size;
}

void StackEx::push(int data)
{
    if (isFull()) {
        cout << "Stack is Full, Overflow" << endl;
        return;
    }
    this->stack[++top] = data;
}

int StackEx::pop()
{
    if (isEmpty()) {
        cout << "Stack is Empty, Underflow" << endl;
        return -1;
    }
    // 삭제된 데이터 반환
    // 논리적으로 삭제만 하고 물리적으로 메모리에서는 삭제하지 않음.
    return this->stack[top--];
}

int StackEx::peek()
{
    return this->stack[top];
}

bool StackEx::isEmpty()
{
    return top == -1;
}

bool StackEx::isFull()
{
    return top == size - 1;
}
void StackEx::Clear()
{
    top = -1;
}
void StackEx::PrintStack()
{
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

StackEx::~StackEx()
{
    delete[] stack;
}
