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

    r2.setNumerator(0);
    std::cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << " = " << r2.getRational() << std::endl;

    r2.setDenominator(0);
    std::cout << "r2 = " << r2.getNumerator() << " / " << r2.getDenominator() << " = " << r2.getRational() << std::endl;

    return 0;
}