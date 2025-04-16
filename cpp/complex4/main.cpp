#include <iostream>
#include "complex.h"

int main()
{
    Complex c1;
    Complex c2 = 6.0;       // Complex c2(6.0);
    Complex c3(9.0, 4.0);
    Complex c4 = c3;        // Complex c4(c3);

    c1 = c3;                // c1.operator=(c3) or operator=(c1, c3)
    c1 = c2 = c3;           // daisy chain

    if (c1 == c3) {
        std::cout << "c1 and c3 are equal" << std::endl;
    } else {
        std::cout << "c1 and c3 are not equal" << std::endl;
    }

    c3 = c1 + c2;
    c4 = c1 - c2;

    if (c3 != c4) {
        std::cout << "c3 and c4 are not equal" << std::endl;
    } else {
        std::cout << "c3 and c4 are equal" << std::endl;
    }

    Complex c5;
    c5 += c2 += c3;

    Complex c6;
    c6 -= c2 -= c3;

    Complex c7;
    c7++;
    ++c7;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c6: " << c6 << std::endl;
    std::cout << "c7: " << c7 << std::endl;

    const Complex c8(2.0, 3.0);
    // c8.getReal(4.0);
    std::cout << "c8: (" << c8.getReal() << " + " << c8.getImag() << "i)" << std::endl;

    return 0;
}