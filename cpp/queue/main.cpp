#include <iostream>
#include "queue.h"

int main()
{
    Queue q1(10), q2(50);
    // initQueue(&q1, 10);
    // initQueue(&q2, 50);

    q1.push(100);
    q1.push(200);
    std::cout << "q1 1st pop(): " << q1.pop() << std::endl;
    q1.push(300);
    std::cout << "q1 2nd pop(): " << q1.pop() << std::endl;
    std::cout << "q1 3rd pop(): " << q1.pop() << std::endl;

    q2.push(900);
    q2.push(800);
    std::cout << "q2 1st pop(): " << q2.pop() << std::endl;
    q2.push(700);
    std::cout << "q2 2nd pop(): " << q2.pop() << std::endl;
    std::cout << "q2 3rd pop(): " << q2.pop() << std::endl;

    // cleanupQueue(&q1);
    // cleanupQueue(&q2);

    return 0;
}