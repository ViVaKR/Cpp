// Stack.h
#ifndef StackEx_H
#define StackEx_H

class StackEx
{
  private:
    int *stack; // 동적 메모리의 주소를 저장할 포인소
    int top;
    int size;

  public:
    StackEx(int size);
    void push(int data);
    int pop();
    int peek();
    bool isEmpty();
    bool isFull();
    ~StackEx();
};

#endif
