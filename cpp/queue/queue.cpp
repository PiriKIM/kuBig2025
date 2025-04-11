#include <cstdio>
#include <cassert>
#include "queue.h"

Queue::Queue(int size)
{
    // pq->pArr = malloc(sizeof(int) * size);
    this->pArr = new int[size];
    // ps->pArr == NULL ??? 예외처리
    // assert(조건식) -> 참이면 계속 진행, 거짓이면 프로그램 종료
    // assert 함수는 디버깅 모드에서만 작동, 릴리즈 모드에서는 작동X
    assert(this->pArr/* != NULL */);      // malloc 실패 시 0 (NULL) 반환
    this->size = size;
    this->rear = 0;
    this->front = 0;
}

Queue::~Queue()
{
    // free(pq->pArr);
    delete [] this->pArr;
}

void Queue::push(int data)
{
    // Full???
    assert(this->rear != this->size);

    this->pArr[this->rear] = data;
    this->rear++;
}

int Queue::pop()
{
    // Empty???
    assert(this->front != this->rear);

    int i = this->front;
    this->front++;
    return this->pArr[i];
}