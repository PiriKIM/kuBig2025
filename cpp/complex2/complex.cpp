#include "complex.h"

Complex::Complex(double re, double im)
{
    this->re = re;
    this->im = im;
}

Complex::Complex(double re)
{
    this->re = re;
    this->im = 0.0;
}

Complex::Complex()
{
    this->re = 0.0;
    this->im = 0.0;
}

Complex::~Complex()
{

}

// void Complex::operator=(Complex c)
// {
//     this->re = c.re;
//     this->im = c.im;
// }

// void Complex::operator=(const Complex *pc)
// {
//     this->re = pc->re;
//     this->im = pc->im;
// }

void Complex::operator=(const Complex &rc)
{
    this->re = rc.re;
    this->im = rc.im;
}

bool Complex::operator==(const Complex &rc)
{
    // if (this->re == rc.re && this->im == rc.im) {
    //     return true;
    // } else {
    //     return false;
    // }
    return (this->re == rc.re && this->im == rc.im);
}

void Complex::operator+(const Complex &rc)
{
    this->re += rc.re;
    this->im += rc.im;
}

double Complex::real()
{
    return this->re;
}

double Complex::imag()
{
    return this->im;
}

void Complex::real(double re)
{
    this->re = re;
}

void Complex::imag(double im)
{
    this->im = im;
}