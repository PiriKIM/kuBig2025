#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> test_vector = {1, 2, 3, 4, 5, 6};
    // for문 첫번째 방식
    for (int i = 0; i < test_vector.size(); ++i)
        cout << test_vector[i] << endl;

    // for문 두번째 방식
    for (vector<int>::iterator it = test_vector.begin(); it != test_vector.end(); ++it)
        cout << *it << endl;

    // iterator가 정의되어있어야 가능 - begin(), end()
    // *it 역참조가 가능해야한다.
    for (auto v : test_vector)  // 세번째 방식 모던 C++
        cout << v << endl;

    // 메모리 공간 절약 & 값 변경도 가능
    for (auto &v : test_vector)  // 세번째 방식 모던 C++
        cout << v << endl;

    // 메모리 공간 절약 & Read Only
    for (const auto &v : test_vector)  // 세번째 방식 모던 C++
        cout << v << endl;

    return 0;
}