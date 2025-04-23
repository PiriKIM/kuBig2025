#include <iostream>
#include <memory>
using namespace std;

class B;

class A
{
public:
    shared_ptr<B> b_ptr;
    ~A() { cout << "A destruct!!" << endl; }
};

class B
{
public:
    shared_ptr<A> a_ptr;
    ~B() { cout << "B destruct!!" << endl; }
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    // 순환 참조로 인한 메모리 누수 발생
    // 하지만 컴파일러가 잡아주지 못 함
    return 0;
}