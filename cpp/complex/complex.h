#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:    // implementation
    double re;      // 실수 real part
    double im;      // 허수 imaginary part

public:     // interface
    Complex(double re, double im);      // constructor
    Complex(double re);
    Complex();                          // function overloading
    ~Complex();                         // destructor

    double real();
    double imag();
    void real(double re);
    void imag(double im);

};

#endif