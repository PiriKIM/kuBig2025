#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{

public:                            // interface
    Complex(double re, double im); // constructor
    Complex(double re);
    Complex();  // function overloading
    ~Complex(); // destructor

    // void operator=(Complex c);
    // void operator=(const Complex *pc);
    void operator=(const Complex &rc);

    bool operator==(const Complex &rc);

    void operator+(const Complex &rc);

    double real();
    double imag();
    void real(double re);
    void imag(double im);

private:       // implementation
    double re; // 실수 real part
    double im; // 허수 imaginary part
};

#endif