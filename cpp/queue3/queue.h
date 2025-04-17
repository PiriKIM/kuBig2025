#ifndef QUEUE_H
#define QUEUE_H
#include "array.h"

class Queue
{
private:
    static const int QUEUE_SIZE;

    // int *pArr_;
    // int size_;
    Array arr_;         // has-a 관계
    int front_;
    int rear_;

    // is not used.
    Queue(const Queue& rhs);
    Queue& operator=(const Queue& rhs);

public:
    static int getDefaultQueueSize();

    // Queue() { }
    explicit Queue(int size = QUEUE_SIZE);
    ~Queue();

    bool operator==(const Queue& rhs) const;

    // Queue *operator&() { return this; }
    // const Queue *operator&() const { return this; }

    int size() const;
    int remain() const;
    int front() const;
    int rear() const;

    bool isEmpty() const;// has-a 관계
    bool isFull() const;

    void push(int data);
    int pop();

};

#endif