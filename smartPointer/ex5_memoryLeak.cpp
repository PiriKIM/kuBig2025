#include <iostream>
#include <memory>
using namespace std;

class B;
class C;

class A
{
public:
    shared_ptr<B> b_ptr;
    ~A() { cout << "A destruct!!" << endl; }
};

class B
{
public:
    shared_ptr<C> c_ptr;
    ~B() { cout << "B destruct!!" << endl; }
};

class C
{
public:
    shared_ptr<A> a_ptr;
    ~C() { cout << "C destruct!!" << endl; }
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    auto c = make_shared<C>();
    a->b_ptr = b;
    b->c_ptr = c;
    c->a_ptr = a;
    // 순환 참조로 인한 메모리 누수 발생
    // 하지만 컴파일러가 잡아주지 못 함
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;
    cout << "c use_count: " << c.use_count() << endl;
    return 0;
}