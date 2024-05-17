#include "../headers/StackEx.h"

StackEx::StackEx(int size)
{
    stack = new int[size];
    top = -1;
    this->size = size;
}

void StackEx::push(int data)
{
}

int StackEx::pop()
{
    return 0;
}

int StackEx::peek()
{
    return 0;
}

bool StackEx::isEmpty()
{
    return false;
}

bool StackEx::isFull()
{
    return false;
}

StackEx::~StackEx()
{
    delete[] stack;
}
