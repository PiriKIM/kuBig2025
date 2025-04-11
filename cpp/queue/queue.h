#ifndef QUEUE_H
#define QUEUE_H

class Queue
{
private:
    int *pArr;
    int size;       // queue's size
    int rear;       // enqueue location
    int front;      // dequeue location

public:
    Queue(int size);
    ~Queue();
    
    void push(int data);
    int pop();
};

#endif