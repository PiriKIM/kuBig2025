#include <iostream>
#include "array.h"

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    Array arr1(nums, 5);
    Array arr2(10);     // Array arr2 = 10; 코드가 동작 못 하도록 헤더 파일 조치.
    Array arr3;         // Array arr3(100);
    Array arr4 = arr1;

    arr2 = arr1;
    if (arr1 == arr2) {
        std::cout << "arr1 and arr2 are equal" << std::endl;
    } else {
        std::cout << "arr1 and arr2 are not equal" << std::endl;
    }

    for (int i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < arr4.size(); ++i) {
        std::cout << arr4[i] << " ";
    }
    std::cout << std::endl;

    // std::cout << "ARRAY_SIZE: " << ARRAY_SIZE << std::endl;
    // std::cout << "ARRAY_SIZE: " << Array::ARRAY_SIZE << std::endl;
    std::cout << "ARRAY_SIZE: " << Array::getDefaultArraySize() << std::endl;

    return 0;
}