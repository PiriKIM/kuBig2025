#include <cstdio>
#include <cassert>
#include "stack.h"
// 생성자
Stack::Stack(int size)
{
    // this->pArr = (int *)malloc(sizeof(int) * size);
    this->pArr = new int[size];
    // this->pArr == NULL ??? 예외처리
    // assert(조건식) -> 참이면 계속 진행, 거짓이면 프로그램 종료
    // assert 함수는 디버깅 모드에서만 작동, 릴리즈 모드에서는 작동X
    assert(this->pArr/* != NULL */);      // malloc 실패 시 0 (NULL) 반환
    this->size = size;
    this->tos = 0;
}
// 소멸자
Stack::~Stack()
{
    // free(this->pArr);
    delete [] this->pArr;
}

void Stack::push(int data)
{
    // Full???
    assert(this->tos != this->size);
    // ps->pArr[ps->tos] = data;
    // ps->tos++;
    *(this->pArr + this->tos) = data;
    this->tos++;
}

int Stack::pop()
{
    // Empty???
    assert(this->tos != 0);
    // ps->tos--;
    // return ps->pArr[ps->tos];
    this->tos--;
    return *(this->pArr + this->tos);
}