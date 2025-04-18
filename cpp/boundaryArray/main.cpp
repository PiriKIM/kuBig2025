#include <iostream>
#include "boundaryArray.h"

int main()
{
    BoundaryArray arr0(6, 23);     // index : [1, 11)  1 ~ 10
    BoundaryArray arr1(1, 18);     // index : [1, 11)  1 ~ 10
    BoundaryArray arr2(10);        // index : [0, 10)
    BoundaryArray arr3;            // index : [0, 100)

    for (int i = arr0.lower(); i != arr0.upper(); ++i) {
        arr0[i] = i;
    }

    for (int i = arr1.lower(); i != arr1.upper(); ++i) {
        arr1[i] = i;
    }

    for (int i = arr2.lower(); i != arr2.upper(); ++i) {
        arr2[i] = i;
    }

    for (int i = arr3.lower(); i != arr3.upper(); ++i) {
        arr3[i] = i;
    }

    std::cout << "arr0 size : " << arr0.size() << ", initVal : " << arr0[arr0.lower()] << ", lastVal : " << arr0[arr0.upper() - 1] << std::endl;
    std::cout << "arr1 size : " << arr1.size() << ", initVal : " << arr1[arr1.lower()] << ", lastVal : " << arr1[arr1.upper() - 1] << std::endl;
    std::cout << "arr2 size : " << arr2.size() << ", initVal : " << arr2[arr2.lower()] << ", lastVal : " << arr2[arr2.upper() - 1] << std::endl;
    std::cout << "arr3 size : " << arr3.size() << ", initVal : " << arr3[arr3.lower()] << ", lastVal : " << arr3[arr3.upper() - 1] << std::endl;
    
    const BoundaryArray arr4 = arr1;
    
    arr3 = arr1;
    
    std::cout << "(arr0 == arr1) : " << (arr0 == arr1) << std::endl;
    std::cout << "(arr4 == arr1) : " << (arr4 == arr1) << std::endl;
    std::cout << "(arr3 == arr1) : " << (arr3 == arr1) << std::endl;

    for (int i = arr4.lower(); i != arr4.upper(); ++i) {
        std::cout << "arr4[" << i << "] : " << arr4[i] << std::endl;
    }
    
    return 0;
}