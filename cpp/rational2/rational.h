#ifndef RATIONAL_H
#define RATIONAL_H

class Rational{
private:
    int numerator;
    int denominator;

public:
    Rational(int numerator, int denominator);
    Rational(int numerator);
    Rational();
    ~Rational();

    void operator=(const Rational &rr);

    bool operator==(const Rational &rr);

    double getRational();
    int getNumerator();
    int getDenominator();
    void setNumerator(int numerator);
    void setDenominator(int denominator);

};

#endif