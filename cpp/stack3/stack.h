#ifndef STACK_H
#define STACK_H
#include "array.h"

class Stack
{
private:
    static const int STACK_SIZE;

    // int *pArr_;
    // int size_;
    Array arr_;         // has-a 관계
    int tos_;

    // is not uerd.
    Stack(const Stack& rhs);
    Stack& operator=(const Stack& rhs);

public:
    static int getDefaultStackSize();

    // Stack() { }
    explicit Stack(int size = STACK_SIZE);
    ~Stack();

    bool operator==(const Stack& rhs) const;

    // Stack *operator&() { return this; }
    // const Stack *operator&() const { return this; }

    int size() const;
    int remain() const;

    bool isEmpty() const;
    bool isFull() const;

    void push(int data);
    int pop();
};

#endif