#include <iostream>
#include "stack.h"

int main()
{
    Stack s1(10);       // Stack s1 = 10; X
    Stack s2;           // Stack s2(100);
    // Stack s3 = s2;   // ??? X

    s1.push(100);
    s1.push(200);
    s1.push(300);

    std::cout << "s1 capacity : " << s1.size() << std::endl;
    std::cout << "s1 remain : " << s1.remain() << std::endl;

    while (!s1.isEmpty()) {
        std::cout << s1.pop() << std::endl;
    }

    std::cout << "s1 capacity : " << s1.size() << std::endl;
    std::cout << "s1 remain : " << s1.remain() << std::endl;
    std::cout << "s2 capacity : " << s2.size() << std::endl;
    std::cout << "s2 remain : " << s2.remain() << std::endl;

    return 0;
}