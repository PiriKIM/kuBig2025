#include <iostream>
#include <memory>
using namespace std;

class B;

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
    weak_ptr<A> a_ptr;
    weak_ptr<A> a_ptr1;
    weak_ptr<A> a_ptr2;
    weak_ptr<A> a_ptr3;
    ~B() { cout << "B destruct!!" << endl; }
};

int main()
{
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->b_ptr = b;
    a->b_ptr1 = b;
    a->b_ptr2 = b;
    a->b_ptr3 = b;
    b->a_ptr = a;
    b->a_ptr1 = a;
    b->a_ptr2 = a;
    b->a_ptr3 = a;
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;
    cout << a->b_ptr->b_var << endl;
    cout << b->a_ptr.lock()->a_var << endl;
    return 0;
}