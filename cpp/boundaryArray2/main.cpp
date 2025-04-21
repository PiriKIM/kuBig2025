#include <iostream>
#include "boundaryArray.h"
#include "complex.h"

int main()
{
    BoundaryArray<int> arr1(1, 11);
    for (int i = arr1.lower(); i != arr1.upper(); ++i) {
        arr1[i] = i;
    }
    for (int i = arr1.lower(); i != arr1.upper(); ++i) {
        std::cout << i << " : " << arr1[i] << std::endl;
    }

    BoundaryArray<double> arr2(5, 11);
    for (int i = arr2.lower(); i != arr2.upper(); ++i) {
        arr2[i] = i;
    }
    for (int i = arr2.lower(); i != arr2.upper(); ++i) {
        std::cout << i << " : " << arr2[i] << std::endl;
    }

    BoundaryArray<Complex> arr3(6, 23);
    for (int i = arr3.lower(); i != arr3.upper(); ++i) {
        arr3[i] = Complex((double)i, (double)i - arr3.lower());
    }
    for (int i = arr3.lower(); i != arr3.upper(); ++i) {
        std::cout << i << " : " << arr3[i] << std::endl;
    }

    return 0;
}