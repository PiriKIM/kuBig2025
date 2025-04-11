#ifndef STACK_H
#define STACK_H
class Stack{
private:
    int *pArr;
    int size;
    int tos;

public:
    // void initStack(int size);    생성자로 만들자
    // void cleanupStack();         소멸자로 만들자
    Stack(int size);
    ~Stack();

    void push(int data);
    int pop();
};

#endif