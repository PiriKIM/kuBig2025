#include <iostream>
#include "rational.h"

int main()
{
    Rational r1;
    Rational r2(5);
    Rational r3(1, 3);
    Rational r4 = r3;

    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    std::cout << "r4 = " << r4 << std::endl;

    Rational r5(4, 16), r6(6, 24);

    std::cout << "r5 = " << r5 << std::endl;
    std::cout << "r6 = " << r6 << std::endl;

    if (r5 == r6) {
        std::cout << "r5 and r6 are equal" << std::endl;
    } else {
        std::cout << "r5 and r6 are not equal" << std::endl;
    }

    r1 = r3 + r4;
    r2 = r1 - r4;
    
    std::cout << "r1 = " << r1 << std::endl;
    std::cout << "r2 = " << r2 << std::endl;
    std::cout << "r3 = " << r3 << std::endl;
    std::cout << "r4 = " << r4 << std::endl;

    Rational r7(2, 7);

    r1 = r5 + r7;
    std::cout << "r1 = " << r1 << std::endl;
    r2 = r6 - r7;
    std::cout << "r2 = " << r2 << std::endl;

    if (r1 != r2) {
        std::cout << "r1 and r2 are not equal" << std::endl;
    } else {
        std::cout << "r1 and r2 are equal" << std::endl;
    }
    
    r7++;
    std::cout << "r7 = " << r7 << std::endl;
    ++r7;
    std::cout << "r7 = " << r7 << std::endl;

    Rational r8(9, 4);
    Rational r9(2, 3);

    r8 += r9 += r9;
    std::cout << "r8 = " << r8 << std::endl;
    r8 -= r7 += r7;
    std::cout << "r8 = " << r8 << std::endl;

    return 0;
}