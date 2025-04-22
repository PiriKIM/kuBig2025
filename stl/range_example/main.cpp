#include <iostream>
#include "processor.h"

using namespace std;

constexpr int factorial(int n)
{
    return n <= 1 ? 1 : n * factorial(n - 1);
}

int main()
{
    // constexpr TEST
    constexpr int fact = factorial(5);  // 컴파일 타임 계산!
    cout << "Factorial(5) : " << fact << endl;

    // 범위 기반 for 문
    vector<string> input = {"hello", "", "world"};
    Processor proc(input);

    auto transformed = proc.transform();
    cout << "transformed data : " << endl;
    for (const auto &s : transformed)
        cout << s << endl;

    // if constexpr TEST
    cout << "Compute tests : " << endl;
    cout << "Int 10 : " << proc.compute(10) << endl;
    cout << "Float 15.0 : " << proc.compute(15.0) << endl;
    cout << "String 'test' : " << proc.compute("test") << endl;

    // nullptr TEST
    string *ptr = nullptr;  // 초기화 안하면 쓰레기값
    cout << "Pointer is : " << (ptr == nullptr ? "null" : "non-null") << endl;
    string a = "Non nullptr!!!";
    ptr = &a;
    cout << "Pointer is : " << (ptr == nullptr ? "null" : "non-null") << endl;

    return 0;
}