#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
    // ps->tos = 0;
    (*ps).tos = 0;
}

void push(Stack *ps, int data)
{
    // Full???
    if (ps->tos == STACKSIZE)
    {
        fprintf(stderr, "stack is full.\n");
        exit(1);    // 프로그램 종료
    }
    // ps->array[ps->tos] = data;
    // ps->tos++;
    (*ps).array[(*ps).tos] = data;
    (*ps).tos++;
}

int pop(Stack *ps)
{
    // Empty???
    if (ps->tos == 0)
    {
        fprintf(stderr, "stack is empty.\n");
        exit(2);    // 프로그램 종료
    }
    // ps->tos--;
    // return ps->array[ps->tos];
    (*ps).tos--;
    return (*ps).array[(*ps).tos];
}