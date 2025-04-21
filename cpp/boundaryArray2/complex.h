#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex
{
// friend 함수, private에 접근 허용
friend std::ostream& operator<<(std::ostream& out, const Complex& rhs);

private:
    double re_;
    double im_;

public:
    Complex(double re = 0.0, double im = 0.0);      // default argument constructor
    // Complex() { }
    // Complex(const Complex& rhs) { /*memberwise copy*/ }
    // ~Complex() { }

    // Complex& operator=(const Complex& rhs) { /*memberwise copy*/ return *this; }
    Complex& operator+=(const Complex& rhs);
    Complex& operator-=(const Complex& rhs);
    // *=, /=  O
    // %=, &=, |=, ^=  X

    bool operator==(const Complex& rhs) const;
    bool operator!=(const Complex& rhs) const;
    // >, <, <=, >=
    
    const Complex operator+(const Complex& rhs) const;
    const Complex operator-(const Complex& rhs) const;
    // *, /
    // %  X

    Complex& operator++();      // prefix   전위증감
    Complex operator++(int );   // postfix  후위증감
    // ++, --  X


    // &, |, ~, ^  X


    // type casting  X


    // Complex *operator&() { return this; }
    // const Complex *operator&() const { return this; }

    double getReal() const;
    double getImag() const;
    void setReal(double re);
    void setImag(double im);
};

#endif