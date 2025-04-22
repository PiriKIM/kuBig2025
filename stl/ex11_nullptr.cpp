#include <iostream>

void func(int) { std::cout << "int\n"; }
void func(int *) { std::cout << "pointer\n"; }
void func(long) { std::cout << "long\n"; }



int main()
{
    int *ptr = nullptr;
    int *ptr2 = NULL;
    int *fp;
    if (ptr == nullptr)
    {
        std::cout << "Null Pointer" << std::endl;
    }

    if (ptr2 == nullptr)
    {
        std::cout << "Null Pointer2" << std::endl;
    }

    func(0L);
    func(1);
    func(NULL);     // nullpointer로 안가짐. long으로 출력.
    func(nullptr);
    func(ptr);
    func(ptr2);
    func(fp);

    return 0;
}