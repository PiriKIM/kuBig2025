#include <iostream>
#include "empty.h"

int main()
{
    Empty e1;               // 기본 생성자
    Empty e2 = e1;          // 복사 생성자

    e1 = e2;                // 치환 연산

    Empty *p1 = &e1;        // 주소값 리턴 연산

    const Empty e3;         // 상수 객체 생성
    const Empty *p2 = &e3;  // 상수 객체를 통한 호출

    return 0;               // 소멸자 실행
}