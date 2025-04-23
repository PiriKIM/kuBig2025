#include <iostream>
#include <memory>
using namespace std;

void useShared(shared_ptr<int> ptr)
{
    cout << "넘겨받은 ptr 의 use count : " << ptr.use_count() << endl;
}

int main()
{
    auto a = make_shared<int>(100);
    auto b = a;     // 포인터에 대한 참조가 생겼다!!
    auto c = a;

    useShared(a);
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;

    useShared(move(a));
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;

    b = a;      cout << "b = a" << endl;
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;

    a = c;      cout << "a = c" << endl;
    cout << "a use_count: " << a.use_count() << endl;
    cout << "b use_count: " << b.use_count() << endl;

    cout << "a = " << a << endl;
    cout << "is 'a' nullptr?" << (a == nullptr ? "Yes" : "No") << endl;
    cout << "b = " << b << endl;
    cout << "is 'b' nullptr?" << (b == nullptr ? "Yes" : "No") << endl;

    return 0;
}