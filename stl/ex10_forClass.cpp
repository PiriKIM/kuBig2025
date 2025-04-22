#include <cstddef>
#include <iostream>

using namespace std;

template <typename T, size_t N>
class MyContainer
{
private:
    T data_[N];

public:
    MyContainer()
    {
        for (size_t i = 0; i < N; ++i)
        {
            data_[i] = static_cast<T>(i + 1) + 0.1;
        }
    }

    class Iter
    {
    private:
        T *ptr;

    public:
        using iterator_category = forward_iterator_tag;
        using value_type = T;
        using difference_type = ptrdiff_t;
        using pointer = T *;
        using reference = T &;

        explicit Iter(T* p) : ptr(p) { }
        reference operator*() const { return *ptr; }
        pointer operator->() { return ptr; }
        Iter& operator++()  // 전위
        {
            ++ptr;
            return *this;
        }
        Iter operator++(int) // 후위
        {
            Iter temp = *this;
            ++(*this);
            return temp;
        }
        friend bool operator==(const Iter &a, const Iter &b)
        {
            return a.ptr == b.ptr;
        }
        friend bool operator!=(const Iter &a, const Iter &b)
        {
            return a.ptr != b.ptr;
        }
    };

    Iter begin() { return Iter(data_); }
    Iter end() { return Iter(data_ + N); }
};

int main()
{
    MyContainer<int, 10> container;

    for (auto v : container)
    {
        cout << v << " ";
    }
    cout << endl;

    MyContainer<double, 10> container2;

    for (auto v2 : container2)
    {
        cout << v2 << " ";
    }
    cout << endl;

    return 0;
}