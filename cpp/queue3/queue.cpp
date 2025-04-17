#include <cassert>
#include "queue.h"

const int Queue::QUEUE_SIZE = 100;

int Queue::getDefaultQueueSize() { return Queue::QUEUE_SIZE; }

Queue::Queue(int size)
: arr_(size), front_(0), rear_(0)
{
}

Queue::~Queue()
{
}

bool Queue::operator==(const Queue& rhs) const
{
    if (arr_.size() != rhs.arr_.size() || front_ != rhs.front_ || rear_ != rhs.rear_) {
        return false;
    }

    int i;
    for (i = rhs.front_; i < rhs.rear_; ++i) {
        if (arr_[i] != rhs.arr_[i]) {
            break;
        }
    }

    return (i == rhs.rear_);
}

int Queue::size() const { return arr_.size();}
int Queue::remain() const { return arr_.size() - rear_; }
int Queue::front() const { return arr_[front_]; }
int Queue::rear() const { return arr_[rear_ - 1]; }

bool Queue::isEmpty() const { return rear_ == front_; }
bool Queue::isFull() const { return rear_ == arr_.size(); }

void Queue::push(int data)
{
    assert(!isFull());
    arr_[rear_] = data;
    ++rear_;
}
int Queue::pop()
{
    assert(!isEmpty());
    int i = front_;
    ++front_;
    return arr_[i];
}