// 값으로 부른다.(call by value)
// 참조로 부른다.(call by reference)
#include <stdio.h>

int f1(void);
int f2(int *pResult);

int main(void)
{
    int f1_result = f1();
    printf("f1 의 반환 결과는 : %d\n", f1_result);

    int f2_result;
    f2(&f2_result);
    printf("f2 의 처리 결과는 : %d\n", f2_result);

    return 0;
}

int f1(void)
{
    return 100;
}

int f2(int *pResult)
{
    *pResult = 100;
}