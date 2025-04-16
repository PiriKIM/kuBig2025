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
    // helper function or tool function
    void reduce();

public:
    Rational(int numer = 0, int denom = 1);      // default argument constructor
    // Rational() { }
    // Rational(const Rational& rhs) { /*memberwise copy*/ }
    // ~Rational() { }
    
    // Rational& operator=(const Rational& rhs) { /*memberwise copy*/ return *this; }
    Rational& operator+=(const Rational& rhs);
    Rational& operator-=(const Rational& rhs);
    // *=, /=  O
    
    bool operator==(const Rational& rhs) const;
    bool operator!=(const Rational& rhs) const;
    // >, <, <=, >=

    const Rational operator+(const Rational& rhs) const;
    const Rational operator-(const Rational& rhs) const;
    // *, /

    // Rational *operator&() { return this; }
    // const Rational *operator&() const { return this; }

    int getNumer() const;
    int getDenom() const;
    void setNumer(int numer);
    void setDenom(int denom);
};

#endif