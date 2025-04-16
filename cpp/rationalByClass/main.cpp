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

    return 0;
}