#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "queue.h"

void initQueue(Queue *pq, int size, int eleSize)
{
    pq->pArr = malloc(eleSize * size);
    // ps->pArr == NULL ??? 예외처리
    // assert(조건식) -> 참이면 계속 진행, 거짓이면 프로그램 종료
    // assert 함수는 디버깅 모드에서만 작동, 릴리즈 모드에서는 작동X
    assert(pq->pArr/* != NULL */);      // malloc 실패 시 0 (NULL) 반환
    pq->eleSize = eleSize;
    pq->size = size;
    pq->rear = 0;
    pq->front = 0;
}

void cleanupQueue(Queue *pq)
{
    free(pq->pArr);
}

void push(Queue *pq, const void *pData)
{
    // Full???
    assert(pq->rear != pq->size);

    memcpy((unsigned char *)pq->pArr + pq->rear * pq->eleSize, pData, pq->eleSize);
    pq->rear++;
}

void pop(Queue *pq, void *pData)
{
    // Empty???
    assert(pq->front != pq->rear);

    memcpy(pData, (unsigned char *)pq->pArr + pq->front * pq->eleSize, pq->eleSize);
    pq->front++;
}