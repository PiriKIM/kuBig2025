#include "boundaryArray.h"

BoundaryArray::BoundaryArray(int size)
: SafeArray(size), low_(0)
{

}

BoundaryArray::BoundaryArray(int low, int upper)
: SafeArray(upper - low), low_(low)
{

}

BoundaryArray::BoundaryArray(const BoundaryArray& rhs)
: SafeArray((SafeArray)rhs), low_(rhs.low_)
{

}

BoundaryArray& BoundaryArray::operator=(BoundaryArray& rhs)
{
    if (this != &rhs) {
        this->SafeArray::operator=((SafeArray)rhs);
        low_ = rhs.low_;
    }
    return *this;
}

bool BoundaryArray::operator==(const BoundaryArray& rhs) const
{
    return low_ == rhs.low_ && this->SafeArray::operator==((SafeArray)rhs);
}

int& BoundaryArray::operator[] (int index)
{
    return this->SafeArray::operator[](index - low_);
}

const int& BoundaryArray::operator[] (int index) const
{
    return this->SafeArray::operator[](index - low_);
}

int BoundaryArray::lower() const { return low_; }
int BoundaryArray::upper() const { return low_ + Array::size_; }