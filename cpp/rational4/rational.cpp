#include <cassert>
#include "rational.h"

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
    return out << rhs.numer_ << " / " << rhs.denom_ << " = " << (double)rhs.numer_ / rhs.denom_;
}

int Rational::abs(int num)
{
    if (num < 0) return -num;
    else         return num;
}

int Rational::gcd(int numer, int denom)
{
    numer = abs(numer);
    denom = abs(denom);
    while (denom != 0)
    {
        int temp = denom;
        denom = numer % denom;
        numer = temp;
    }

    return numer;
}

int Rational::lcm(int denom1, int denom2)
{
    return abs(denom1 * denom2) / gcd(denom1, denom2);
}

const Rational Rational::simplify(const Rational& rhs)
{
    int gcdNum = gcd(rhs.numer_, rhs.denom_);
    Rational result(rhs.numer_ / gcdNum, rhs.denom_ / gcdNum);
    return result;
}

Rational::Rational(int numer, int denom)
{
    assert(denom != 0);
    numer_ = numer;
    denom_ = denom;
}

Rational& Rational::operator+=(const Rational& rhs)
{
    *this = *this + rhs;
    return *this;
}

Rational& Rational::operator-=(const Rational& rhs)
{
    *this = *this - rhs;
    return *this;
}

bool Rational::operator==(const Rational& rhs)
{
    // return (numer_ * rhs.denom_ == denom_ * rhs.numer_);
    Rational r1 = simplify(*this), r2 = simplify(rhs);
    return (r1.numer_ == r2.numer_) && (r1.denom_ == r2.denom_);
}

bool Rational::operator!=(const Rational& rhs)
{
    // return (numer_ * rhs.denom_ != denom_ * rhs.numer_);
    Rational r1 = simplify(*this), r2 = simplify(rhs);
    return (r1.numer_ != r2.numer_) || (r1.denom_ != r2.denom_);
    // return !this->operator==(rhs);
    // return !(*this == rhs);
}

const Rational Rational::operator+(const Rational& rhs)
{
    int lcmNum = lcm(denom_, rhs.denom_);
    Rational result((numer_ * (lcmNum / denom_)) + (rhs.numer_ * (lcmNum / rhs.denom_)), lcmNum);
    result = simplify(result);
    return result;
}

const Rational Rational::operator-(const Rational& rhs)
{
    int lcmNum = lcm(denom_, rhs.denom_);
    Rational result((numer_ * (lcmNum / denom_)) - (rhs.numer_ * (lcmNum / rhs.denom_)), lcmNum);
    result = simplify(result);
    return result;
}

Rational& Rational::operator++()
{
    numer_ += 1;

    return *this;
}

Rational Rational::operator++(int )
{
    Rational tmp = *this;
    numer_ += 1;

    return tmp;
}