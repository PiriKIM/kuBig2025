#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    void *pArr;
    int eleSize;    // element size
    int size;       // queue's size
    int rear;       // enqueue location
    int front;      // dequeue location
} Queue;

void initQueue(Queue *pq, int size, int eleSize);
void cleanupQueue(Queue *pq);
void push(Queue *pq, const void *pData);
void pop(Queue *pq, void *pData);

#endif