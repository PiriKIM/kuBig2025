#include <cassert>
#include "rational.h"

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
    out << rhs.numerator << " / " << rhs.denominator << " = " << (double)rhs.numerator / rhs.denominator;

    return out;
}

Rational::Rational(int numerator, int denominator)
{
    assert(denominator != 0);
    int gcdNum = gcd(numerator, denominator);
    this->numerator = numerator / gcdNum;
    this->denominator = denominator / gcdNum;
}
Rational::Rational(const Rational& rhs)    // right hand side 우항
{
    this->numerator = rhs.numerator;
    this->denominator= rhs.denominator;
}
Rational::~Rational()
{

}

int Rational::gcd(int numerator, int denominator)
{
    while (denominator != 0)
    {
        int temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }

    return numerator;
}

int Rational::lcm(int denominator1, int denominator2)
{
    return (denominator1 * denominator2) / gcd(denominator1, denominator2);
}

const Rational Rational::simplify(const Rational &rhs)
{
    int gcdNum = gcd(rhs.numerator, rhs.denominator);
    Rational result((rhs.numerator / gcdNum), (rhs.denominator / gcdNum));
    return result;
}

Rational& Rational::operator=(const Rational& rhs)
{
    this->numerator = rhs.numerator;
    this->denominator = rhs.denominator;

    return *this;
}

bool Rational::operator==(const Rational& rhs)
{
    // return (this->numerator * rhs.denominator == this->denominator * rhs.numerator);
    Rational r1 = simplify(*this), r2 = simplify(rhs);
    return (r1.numerator == r2.numerator) && (r1.denominator == r2.denominator);
}

const Rational Rational::operator+(const Rational& rhs)
{
    int lcmNum = lcm(this->denominator, rhs.denominator);
    Rational result((this->numerator * (lcmNum / this->denominator)) + (rhs.numerator * (lcmNum / rhs.denominator)), lcmNum);
    result = simplify(result);
    return result;
}

const Rational Rational::operator-(const Rational& rhs)
{
    int lcmNum = lcm(this->denominator, rhs.denominator);
    Rational result((this->numerator * (lcmNum / this->denominator)) - (rhs.numerator * (lcmNum / rhs.denominator)), lcmNum);
    result = simplify(result);
    return result;
}
