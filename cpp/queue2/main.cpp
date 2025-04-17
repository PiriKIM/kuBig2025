#include <iostream>
#include "queue.h"

int main()
{
    Queue q0(10);
    Queue q1(10);       // Stack s1 = 10; X
    Queue q2;           // Stack s2(100);
    // Stack s3 = s2;   // ??? X
    
    std::cout << "q2 capacity : " << q2.size() << std::endl;
    std::cout << "q2 remain : " << q2.remain() << std::endl;

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
    std::cout << "q0 remain : " << q0.remain() << std::endl;
    std::cout << "q1 capacity : " << q1.size() << std::endl;
    std::cout << "q1 remain : " << q1.remain() << std::endl;

    if (q0 == q1) {
        std::cout << "q0 and q1 are equal" << std::endl;
    } else {
        std::cout << "q0 and q1 are not equal" << std::endl;
    }

    std::cout << "q0.pop() : " << q0.pop() << std::endl;
    std::cout << "q1.pop() : " << q1.pop() << std::endl;
    std::cout << "q0 remain : " << q0.remain() << std::endl;
    std::cout << "q1 remain : " << q1.remain() << std::endl;

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

    std::cout << "q0 remain : " << q0.remain() << std::endl;
    std::cout << "q1 remain : " << q1.remain() << std::endl;

    return 0;
}