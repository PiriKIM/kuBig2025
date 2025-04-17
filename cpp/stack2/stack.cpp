#include <cassert>
#include "stack.h"

const int Stack::STACK_SIZE = 100;

int Stack::getDefaultStackSize() { return Stack::STACK_SIZE; }

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0)
{
    assert(pArr_);
}

Stack::~Stack()
{
    delete [] pArr_;
}

bool Stack::operator==(const Stack& rhs) const
{
    if (size_ != rhs.size_ || tos_ != rhs.tos_) {
        return false;
    }

    int i;
    for (i = 0; i < rhs.tos_; ++i) {
        if (pArr_[i] != rhs.pArr_[i]) {
            break;
        }
    }

    return (i == rhs.tos_);
}

int Stack::size() const { return size_;}
int Stack::remain() const { return size_ - tos_; }

bool Stack::isEmpty() const { return tos_ == 0; }
bool Stack::isFull() const { return tos_ == size_; }

void Stack::push(int data)
{
    assert(!isFull());
    pArr_[tos_] = data;
    ++tos_;
}
int Stack::pop()
{
    assert(!isEmpty());
    --tos_;
    return pArr_[tos_];
}