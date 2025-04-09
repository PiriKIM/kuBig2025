#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int *pArr;
    int size;       // queue's size
    int rear;       // enqueue location
    int front;      // dequeue location
} Queue;

void initQueue(Queue *pq, int size);
void cleanupQueue(Queue *pq);
void push(Queue *pq, int data);
int pop(Queue *pq);

#endif