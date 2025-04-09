#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size, int eleSize)
{
    ps->pArr = malloc(eleSize * size);
    // ps->pArr == NULL ??? 예외처리
    // assert(조건식) -> 참이면 계속 진행, 거짓이면 프로그램 종료
    // assert 함수는 디버깅 모드에서만 작동, 릴리즈 모드에서는 작동X
    assert(ps->pArr/* != NULL */);      // malloc 실패 시 0 (NULL) 반환
    ps->eleSize = eleSize;
    ps->size = size;
    ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps, const void *pData)
{
    // Full???
    assert(ps->tos != ps->size);
    // memcpy(&ps->pArr[ps->tos], pData, ps->eleSize);
    memcpy((unsigned char *)ps->pArr + ps->tos * ps->eleSize, pData, ps->eleSize);
    ps->tos++;
}

void pop(Stack *ps, void *pData)
{
    // Empty???
    assert(ps->tos != 0);

    ps->tos--;
    // memcpy(pData, &ps->pArr[ps->tos], ps->eleSize);
    memcpy(pData, (unsigned char *)ps->pArr + ps->tos * ps->eleSize, ps->eleSize);
}

/*
int pop(Stack *ps)
{
    // Empty???
    assert(ps->tos != 0);
    ps->tos--;
    return ps->pArr[ps->tos];
}
*/