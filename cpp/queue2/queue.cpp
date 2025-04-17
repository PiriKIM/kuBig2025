#include <cassert>
#include "queue.h"

const int Queue::QUEUE_SIZE = 100;

int Queue::getDefaultQueueSize() { return Queue::QUEUE_SIZE; }

Queue::Queue(int size)
: pArr_(new int[size]), size_(size), front_(0), rear_(0)
{
    assert(pArr_);
}

Queue::~Queue()
{
    delete [] pArr_;
}

bool Queue::operator==(const Queue& rhs) const
{
    if (size_ != rhs.size_ || front_ != rhs.front_ || rear_ != rhs.rear_) {
        return false;
    }

    int i;
    for (i = rhs.front_; i < rhs.rear_; ++i) {
        if (pArr_[i] != rhs.pArr_[i]) {
            break;
        }
    }

    return (i == rhs.rear_);
}

int Queue::size() const { return size_;}
int Queue::remain() const { return size_ - rear_; }
int Queue::front() const { return pArr_[front_]; }
int Queue::rear() const { return pArr_[rear_ - 1]; }

bool Queue::isEmpty() const { return rear_ == front_; }
bool Queue::isFull() const { return rear_ == size_; }

void Queue::push(int data)
{
    assert(!isFull());
    pArr_[rear_] = data;
    ++rear_;
}
int Queue::pop()
{
    assert(!isEmpty());
    int i = front_;
    ++front_;
    return pArr_[i];
}