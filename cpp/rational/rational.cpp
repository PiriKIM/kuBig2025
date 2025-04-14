#include <cassert>
#include "rational.h"

Rational::Rational(int numerator, int denominator)
{
    assert(denominator != 0);
    this->numerator = numerator;
    this->denominator = denominator;
}
Rational::Rational(int numerator)
{
    this->numerator = numerator;
    this->denominator = 1;
}
Rational::Rational()
{
    this->numerator = 0;
    this->denominator = 1;
}
Rational::~Rational()
{

}

double Rational::getRational()
{
    return (double)this->numerator / this->denominator;
}
int Rational::getNumerator()
{
    return this->numerator;
}
int Rational::getDenominator()
{
    return this->denominator;
}
void Rational::setNumerator(int numerator)
{
    this->numerator = numerator;
}
void Rational::setDenominator(int denominator)
{
    assert(denominator != 0);
    this->denominator = denominator;
}
