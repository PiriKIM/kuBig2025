#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
public:
    int test_a;
    MyClass()
    {
        cout << "MyClass 생성!!" << endl;
        test_a = 100;
    }
    ~MyClass() { cout << "MyClass 소멸!!" << endl; }
};

int main()
{
    auto ptr = make_unique<MyClass>();  // heap 에 만들어진 메모리.
    // 에러 상황에서도 동작!!
    cout << ptr->test_a / 0 << endl;

    return 0;
}