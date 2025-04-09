#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"

void initStack(Stack *ps, int size)
{
    ps->pArr = malloc(sizeof(int) * size);
    // ps->pArr == NULL ??? 예외처리
    // assert(조건식) -> 참이면 계속 진행, 거짓이면 프로그램 종료
    // assert 함수는 디버깅 모드에서만 작동, 릴리즈 모드에서는 작동X
    assert(ps->pArr/* != NULL */);      // malloc 실패 시 0 (NULL) 반환
    ps->size = size;
    ps->tos = 0;
    // (*ps).tos = 0;
}

void cleanupStack(Stack *ps)
{
    free(ps->pArr);
}

void push(Stack *ps, int data)
{
    // Full???
    // if (ps->tos == ps->size)
    // {
    //     fprintf(stderr, "stack is full.\n");
    //     exit(1);    // 프로그램 종료
    // }
    assert(ps->tos != ps->size);
    // ps->pArr[ps->tos] = data;
    // ps->tos++;
    *(ps->pArr + ps->tos) = data;
    (*ps).tos++;
}

int pop(Stack *ps)
{
    // Empty???
    // if (ps->tos == 0)
    // {
    //     fprintf(stderr, "stack is empty.\n");
    //     exit(2);    // 프로그램 종료
    // }
    assert(ps->tos != 0);
    // ps->tos--;
    // return ps->pArr[ps->tos];
    (*ps).tos--;
    return *(ps->pArr + ps->tos);
}