#include <stdio.h>

int sumArray(int *pArr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += pArr[i];
    }
    return sum;
}

int sumArray2(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i)
    {
        sum += *arr++;
    }
    return sum;
}

int main(void)
{
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // int sum = sumArray(nums, sizeof(nums) / sizeof(int));
    int sum = sumArray(nums + 5, sizeof(nums) / sizeof(int) - 5);
    printf("sum : %d\n", sum);

    int sum2 = sumArray2(nums, sizeof(nums) / sizeof(int));
    printf("sum2 : %d\n", sum2);

    return 0;
}