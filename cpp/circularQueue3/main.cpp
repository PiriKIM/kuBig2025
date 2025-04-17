#include <iostream>
#include "queue.h"

int main()
{
    // 원형큐 비교연산(==) 테스트
    // 큐의 크기, 배열이 가지고 있는 값의 순서가 모두 같으면 true
    // front, rear의 위치는 무시
    Queue q0(7);
    Queue q1(7);

    std::cout << "q0 capacity : " << q0.size() << std::endl;
    std::cout << "q1 capacity : " << q1.size() << std::endl;

    int i = 0;
    q0.push(i += 100);
    q1.push(i += 100);

    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;
    std::cout << "q1 available : " << q1.available() << ", front : " << q1.front() << ", rear : " << q1.rear() << std::endl;

    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    std::cout << "q0.pop() : " << q0.pop() << std::endl;
    std::cout << "q1.pop() : " << q1.pop() << std::endl;

    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;
    std::cout << "q1 available : " << q1.available() << ", front : " << q1.front() << ", rear : " << q1.rear() << std::endl;

    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    while (q0.available() > 2) {
        q0.push(i += 100);
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;
    std::cout << "q1 available : " << q1.available() << ", front : " << q1.front() << ", rear : " << q1.rear() << std::endl;
    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    while (!q0.isEmpty()) {
        std::cout << q0.pop() << std::endl;
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;
    std::cout << "q1 available : " << q1.available() << ", front : " << q1.front() << ", rear : " << q1.rear() << std::endl;
    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    while (q0.available() > 2) {
        q0.push(i += 100);
        q1.push(i);
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;
    std::cout << "q1 available : " << q1.available() << ", front : " << q1.front() << ", rear : " << q1.rear() << std::endl;
    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    while (!q0.isEmpty()) {
        std::cout << "q0.pop() : " << q0.pop() << std::endl;
        std::cout << "q1.pop() : " << q1.pop() << std::endl;
    }

    /*
    // 원형 동작 테스트
    Queue q0(17);
    int i = 0;
    
    std::cout << "q0 capacity : " << q0.size() << std::endl;
    
    while (!q0.isFull()) {
        q0.push(i += 100);
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;

    while (q0.available() < 9) {
        std::cout << q0.pop() << std::endl;
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;

    while (!q0.isFull()) {
        q0.push(i += 100);
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;

    while (q0.available() < 11) {
        std::cout << q0.pop() << std::endl;
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;

    while (!q0.isFull()) {
        q0.push(i += 100);
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;

    while (!q0.isEmpty()) {
        std::cout << q0.pop() << std::endl;
    }
    std::cout << "q0 available : " << q0.available() << ", front : " << q0.front() << ", rear : " << q0.rear() << std::endl;
    */
    

    /*
    // 일반 동작 테스트
    Queue q0(10);
    Queue q1(10);       // Stack s1 = 10; X
    Queue q2;           // Stack s2(100);
    // Stack s3 = s2;   // ??? X
    
    std::cout << "q2 capacity : " << q2.size() << std::endl;
    std::cout << "q2 remain : " << q2.available() << std::endl;

    q0.push(50);
    q0.push(100);
    q0.push(200);
    q0.push(300);
    q0.push(400);

    q1.push(100);
    q1.push(100);
    q1.push(200);
    q1.push(300);
    q1.push(400);

    std::cout << "q0 capacity : " << q0.size() << std::endl;
    std::cout << "q0 remain : " << q0.available() << std::endl;
    std::cout << "q1 capacity : " << q1.size() << std::endl;
    std::cout << "q1 remain : " << q1.available() << std::endl;

    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    std::cout << "q0.pop() : " << q0.pop() << std::endl;
    std::cout << "q1.pop() : " << q1.pop() << std::endl;
    std::cout << "q0 remain : " << q0.available() << std::endl;
    std::cout << "q1 remain : " << q1.available() << std::endl;
    
    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }
    
    while (!q0.isEmpty()) {
        std::cout << q0.pop() << std::endl;
    }
    
    q1.push(500);
    
    while (!q1.isEmpty()) {
        std::cout << q1.pop() << std::endl;
    }
    
    std::cout << "q0 remain : " << q0.available() << std::endl;
    std::cout << "q1 remain : " << q1.available() << std::endl;
    */
    
    return 0;
}