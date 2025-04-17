#include <cassert>
#include "stack.h"

const int Stack::STACK_SIZE = 100;

int Stack::getDefaultStackSize() { return Stack::STACK_SIZE; }

Stack::Stack(int size)
: arr_(size), tos_(0)
{
}

Stack::~Stack()
{
}

bool Stack::operator==(const Stack& rhs) const
{
    if (arr_.size() != rhs.arr_.size() || tos_ != rhs.tos_) {
        return false;
    }

    int i;
    for (i = 0; i < rhs.tos_; ++i) {
        if (arr_[i] != rhs.arr_[i]) {
            break;
        }
    }

    return (i == rhs.tos_);
}

int Stack::size() const { return arr_.size(); }
int Stack::remain() const { return arr_.size() - tos_; }

bool Stack::isEmpty() const { return tos_ == 0; }
bool Stack::isFull() const { return tos_ == arr_.size(); }

void Stack::push(int data)
{
    assert(!isFull());
    arr_[tos_] = data;
    ++tos_;
}
int Stack::pop()
{
    assert(!isEmpty());
    --tos_;
    return arr_[tos_];
}