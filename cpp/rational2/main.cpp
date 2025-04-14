#include <iostream>
#include "rational.h"

int main()
{
    Rational r1(1, 3);
    Rational r2(5);
    Rational r3;

    std::cout << "r1 = " << r1.getNumerator() << " / " << r1.getDenominator() << " = " << r1.getRational() << std::endl;
    std::cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << " = " << r2.getRational() << std::endl;
    std::cout << "r3 = " << r3.getNumerator() << " / " << r3.getDenominator() << " = " << r3.getRational() << std::endl;

    r3.setNumerator(1039);
    r3.setDenominator(237);

    std::cout << "r3 = " << r3.getNumerator() << " / " << r3.getDenominator() << " = " << r3.getRational() << std::endl;

    Rational r4(4, 12), r5(6, 18), r6;

    std::cout << "r4 = " << r4.getNumerator() << " / " << r4.getDenominator() << " = " << r4.getRational() << std::endl;
    std::cout << "r5 = " << r5.getNumerator() << " / " << r5.getDenominator() << " = " << r5.getRational() << std::endl;

    if (r4 == r5) {
        std::cout << "r4 and r5 are equal" << std::endl;
    } else {
        std::cout << "r4 and r5 are not equal" << std::endl;
    }

    std::cout << "r6 = " << r6.getNumerator() << " / " << r6.getDenominator() << " = " << r6.getRational() << std::endl;

    r6 = r3;

    std::cout << "r6 = " << r6.getNumerator() << " / " << r6.getDenominator() << " = " << r6.getRational() << std::endl;

    r2.setNumerator(0);
    std::cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << " = " << r2.getRational() << std::endl;

    r2.setDenominator(0);
    std::cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << " = " << r2.getRational() << std::endl;

    return 0;
}