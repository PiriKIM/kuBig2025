// n 의 제곱을 구하는 함수를 만들어서 2의 62 제곱을 프린트하시오.
#include <stdio.h>

long long power(int base, int exponent);
void power2(int base, int exponent, long long *result);

int main(void)
{
    long long result = power(2, 62);
    printf("2 power of 62 = %lld\n", result);
    long long result2 = 1;
    power2(2, 62, &result2);;
    printf("2 power of 62 = %lld\n", result2);
    printf("long long type max = %lld\n", result * 2 - 1);
    printf("unsigned long long type max = %llu\n", result * 4 - 1);

    return 0;
}

long long power(int base, int exponent)
{
    long long temp = 1;
    for (int i = 0; i < exponent; i++)
    {
        temp *= base;
    }
    return temp;
}

void power2(int base, int exponent, long long *result)
{
    for (int i = 0; i < exponent; i++)
    {
        *result *= base;
    }
}
