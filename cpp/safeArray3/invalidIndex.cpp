#include "invalidIndex.h"

InvalidIndex::InvalidIndex(int index)
: index_(index)
{

}

int InvalidIndex::getInvalid() const
{
    return index_;
}