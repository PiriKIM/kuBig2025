#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
// friend 함수, private에 접근 허용
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:                            // implementation
    double re;  // real part
    double im;  // imaginary part

public:                             // interface
    // Complex();                   // function overloading
    // Complex(double re);
    Complex(double re = 0.0, double im = 0.0);  // default argument constructor
    Complex(const Complex& rhs);                // copy constructor
    ~Complex();                                 // destructor

    // operator overloading
    Complex& operator=(const Complex& rhs);
    bool operator==(const Complex& rhs);

    const Complex operator+(const Complex& rhs);
    const Complex operator-(const Complex& rhs);
};

#endif