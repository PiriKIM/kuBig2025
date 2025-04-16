#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
// friend 함수, private에 접근 허용
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
    int numer_;
    int denom_;

public:
    int abs(int num);
    int gcd(int numer, int denom);
    int lcm(int denom1, int denom2);
    const Rational simplify(const Rational &rhs);

    Rational(int numer = 0, int denom = 1);      // default argument constructor
    // Rational() { }
    // Rational(const Rational& rhs) { /*memberwise copy*/ }
    // ~Rational() { }
    
    // Rational& operator=(const Rational& rhs) { /*memberwise copy*/ return *this; }
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    // *=, /=  O
    // %=, &=, |=, ^=  X
    
    bool operator==(const Rational& rhs);
    bool operator!=(const Rational& rhs);
    // >, <, <=, >=

    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);
    // *, /
    // %  X

    Rational& operator++();      // prefix   전위증감
    Rational operator++(int );   // postfix  후위증감
    // ++, --  X


    // &, |, ~, ^  X


    // type casting  X


    // Rational *operator&() { return this; }
    // const Rational *operator&() const { return this; }
};

#endif