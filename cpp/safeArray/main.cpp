#include <iostream>
#include "safeArray.h"

int main()
{
    SafeArray arr1;
    SafeArray arr2(10);
    int nums[] = {1, 2, 3, 4, 5};
    SafeArray arr3(nums, 5);
    SafeArray arr4 = arr3;

    std::cout << "size of arr1 : " << arr1.size() << ", size of arr2 : " << arr2.size() << std::endl;

    arr1 = arr3;

    std::cout << "(arr1 == arr3) : " << (arr1 == arr3) << std::endl;

    for (int i = 0; i < arr1.size(); ++i)
    {
        std::cout << arr1[i] << std::endl;
    }

    // int i = arr1[7];        // boundary error!!
    Array *p = new SafeArray(nums, 5);
    (*p)[5] = 6;        // p->operator[](5) = 6;
    // -> 실행 시간의 객체의 타입이 아닌 포인터의 타입을 보고 실행함.
    // 부모 쪽 함수 앞에 virtual 키워드를 붙여주면 해결 가능.

    delete p;
    return 0;
}