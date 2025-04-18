#ifndef BOUND_ARRAY_H
#define BOUND_ARRAY_H

#include "safeArray.h"

class BoundaryArray : public SafeArray
{
private:
    int low_;

public:
    explicit BoundaryArray(int size = Array::ARRAY_SIZE);
    BoundaryArray(int low, int upper);
    // BoundaryArray();
    BoundaryArray(const BoundaryArray& rhs);
    // virtual ~BoundaryArray();
    BoundaryArray& operator=(BoundaryArray& rhs);

    bool operator==(const BoundaryArray& rhs) const;

    virtual int& operator[] (int index);
    virtual const int& operator[] (int index) const;

    // BoundaryArray *operator&() { return this; }
    // const BoundaryArray *operator&() const { return this; }

    int lower() const;
    int upper() const;

};

#endif