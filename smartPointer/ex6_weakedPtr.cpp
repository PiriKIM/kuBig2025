#include <iostream>
#include <memory>
using namespace std;

class B;
class C;

class A
{
public:
    int a_var = 100;
    shared_ptr<B> b_ptr;
    shared_ptr<B> b_ptr1;
    shared_ptr<B> b_ptr2;
    shared_ptr<B> b_ptr3;
    ~A() { cout << "A destruct!!" << endl; }
};

class B
{
public:
    int b_var = 200;
    shared_ptr<C> c_ptr;
    shared_ptr<C> c_ptr1;
    shared_ptr<C> c_ptr2;
    shared_ptr<C> c_ptr3;
    ~B() { cout << "B destruct!!" << endl; }
};

class C
{
public:
    int c_var = 300;
    weak_ptr<A> a_ptr;
    weak_ptr<A> a_ptr1;
    weak_ptr<A> a_ptr2;
    weak_ptr<A> a_ptr3;
    ~C() { cout << "C destruct!!" << endl; }
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    auto c = make_shared<C>();
    a->b_ptr = b;
    a->b_ptr1 = b;
    a->b_ptr2 = b;
    a->b_ptr3 = b;
    b->c_ptr = c;
    b->c_ptr1 = c;
    b->c_ptr2 = c;
    b->c_ptr3 = c;
    c->a_ptr = a;
    c->a_ptr1 = a;
    c->a_ptr2 = a;
    c->a_ptr3 = a;
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;
    cout << "c use_count: " << c.use_count() << endl;
    cout << a->b_ptr->b_var << endl;
    cout << b->c_ptr->c_var << endl;
    cout << c->a_ptr.lock()->a_var << endl;
    return 0;
}