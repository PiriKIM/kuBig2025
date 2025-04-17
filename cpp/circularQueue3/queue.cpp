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
    if (arr_.size() != rhs.arr_.size() || available() != rhs.available()) {
        return false;
    }

    int i;
    int j = (rhs.front_ - front_ + arr_.size()) % arr_.size();
    for (i = front_; i != rear_; i = ++i % arr_.size()) {
        if (arr_[i] != rhs.arr_[(i + j) % arr_.size()]) {
            break;
        }
    }

    return (i == rear_);
}

int Queue::size() const { return arr_.size() - 1;}
// available = capacity - 1 - ((rear - front + capacity) % capacity)
int Queue::available() const { return arr_.size() - 1 - ((rear_ - front_ + arr_.size()) % arr_.size()); }
int Queue::front() const { return front_; }
int Queue::rear() const { return rear_; }

bool Queue::isEmpty() const { return rear_ == front_; }
bool Queue::isFull() const { return (rear_ + 1) % arr_.size() == front_; }

void Queue::push(int data)
{
    assert(!isFull());
    arr_[rear_] = data;
    rear_ = ++rear_ % arr_.size();
}
int Queue::pop()
{
    assert(!isEmpty());
    int i = front_;
    front_ = ++front_ % arr_.size();
    return arr_[i];
}