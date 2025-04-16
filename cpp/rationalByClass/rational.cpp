#include <cassert>
#include "gcd.h"
#include "rational.h"

std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
    return out << rhs.numer_ << " / " << rhs.denom_ << " = " << (double)rhs.numer_ / rhs.denom_;
}

void Rational::reduce()
{
    int g = gcd(numer_, denom_);
    numer_ /= g;
    denom_ /= g;
}

Rational::Rational(int numer, int denom)
: numer_(numer), denom_(denom)
{
    assert(denom);
    
    this->reduce();
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

bool Rational::operator==(const Rational& rhs) const
{
    // return (numer_ * rhs.denom_ == denom_ * rhs.numer_);
    return (numer_ == rhs.numer_) && (denom_ == rhs.denom_);
}

bool Rational::operator!=(const Rational& rhs) const
{
    // return (numer_ * rhs.denom_ != denom_ * rhs.numer_);
    return (numer_ != rhs.numer_) || (denom_ != rhs.denom_);
    // return !this->operator==(rhs);
    // return !(*this == rhs);
}

const Rational Rational::operator+(const Rational& rhs) const
{
    Rational result(numer_ * rhs.denom_ + rhs.numer_ * denom_, denom_ * rhs.denom_);

    return result;
}

const Rational Rational::operator-(const Rational& rhs) const
{
    Rational result(numer_ * rhs.denom_ - rhs.numer_ * denom_, denom_ * rhs.denom_);

    return result;
}

int Rational::getNumer() const { return numer_; }
int Rational::getDenom() const { return denom_; }
void Rational::setNumer(int numer) { numer_ = numer; }
void Rational::setDenom(int denom) { denom_ = denom; }