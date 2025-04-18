#include <iostream>
#include "complex.h"
#include "safeArray.h"

int main()
{
    char nums0[] = {'A', 'a', 'B', 'b', 'C', 'c'};
    SafeArray<char> arr0(nums0, 6);
    for (int i = 0; i < arr0.size(); ++i){
        std::cout << arr0[i] << " ";
    }
    std::cout << std::endl;

    int nums1[] = {1, 2, 3, 4, 5};
    SafeArray<int> arr1(nums1, 5);
    for (int i = 0; i < arr1.size(); ++i){
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    double nums2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    SafeArray<double> arr2(nums2, 5);
    for (int i = 0; i < arr2.size(); ++i){
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    Complex nums3[] = {Complex(9.0, 4.0), Complex(6.0, 2.0), Complex(3.0, 9.0), Complex(5.0, 7.0), Complex(2.0, 5.0)};
    SafeArray<Complex> arr3(nums3, 5);
    for (int i = 0; i < arr3.size(); ++i){
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}