#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;
    Complex c2 = (6.0);     // Complex c2(6.0);
    Complex c3(9.0, 4.0);
    Complex c4 = c3;        // Complex c4(c3);

    c1 = c3;                // c1.operator=(c3) or operator=(c1, c3)
    c1 = c2 = c3;           // daisy chain

    if (c1 == c3) {         // c1.operator==(c3) or operator==(c1, c3)
        std::cout << "c1 and c3 are equal" << std::endl;
    } else {
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    c3 = c1 + c2;
    c4 = c1 - c2;

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
 
    return 0;
}