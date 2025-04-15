#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational{
// friend 함수, private에 접근 허용
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);

private:
    int numerator;
    int denominator;

public:
    Rational(int numerator = 0, int denominator = 1);
    Rational(const Rational& rhs);
    ~Rational();
    
    int gcd(int numerator, int denominator);
    int lcm(int denominator1, int denominator2);
    const Rational simplify(const Rational& rhs);

    Rational& operator=(const Rational& rhs);
    bool operator==(const Rational& rhs);

    const Rational operator+(const Rational& rhs);
    const Rational operator-(const Rational& rhs);

};

#endif