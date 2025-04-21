#ifndef BOUND_ARRAY_H
#define BOUND_ARRAY_H
#include "safeArray.h"

template <typename T>
class BoundaryArray : public SafeArray<T>
{
private:
    int low_;

public:
    explicit BoundaryArray(int size = Array<T>::ARRAY_SIZE);
    BoundaryArray(int low, int upper);
    // BoundaryArray();
    BoundaryArray(const BoundaryArray<T>& rhs);
    // virtual ~BoundaryArray();
    BoundaryArray<T>& operator=(BoundaryArray<T>& rhs);

    bool operator==(const BoundaryArray<T>& rhs) const;

    virtual T& operator[] (int index);
    virtual const T& operator[] (int index) const;

    // BoundaryArray *operator&() { return this; }
    // const BoundaryArray *operator&() const { return this; }

    int lower() const;
    int upper() const;

};


template <typename T>
BoundaryArray<T>::BoundaryArray(int size)
: SafeArray<T>(size), low_(0)
{

}

template <typename T>
BoundaryArray<T>::BoundaryArray(int low, int upper)
: SafeArray<T>(upper - low), low_(low)
{

}

template <typename T>
BoundaryArray<T>::BoundaryArray(const BoundaryArray<T>& rhs)
: SafeArray<T>((SafeArray<T>)rhs), low_(rhs.low_)
{

}

template <typename T>
BoundaryArray<T>& BoundaryArray<T>::operator=(BoundaryArray<T>& rhs)
{
    if (this != &rhs) {
        this->SafeArray<T>::operator=((SafeArray<T>)rhs);
        low_ = rhs.low_;
    }
    return *this;
}

template <typename T>
bool BoundaryArray<T>::operator==(const BoundaryArray<T>& rhs) const
{
    return low_ == rhs.low_ && this->SafeArray<T>::operator==((SafeArray<T>)rhs);
}

template <typename T>
T& BoundaryArray<T>::operator[] (int index)
{
    return this->SafeArray<T>::operator[](index - low_);
}

template <typename T>
const T& BoundaryArray<T>::operator[] (int index) const
{
    return this->SafeArray<T>::operator[](index - low_);
}

template <typename T>
int BoundaryArray<T>::lower() const { return low_; }
template <typename T>
int BoundaryArray<T>::upper() const { return low_ + Array<T>::size_; }

#endif