#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumArray(int pArray[], int size);   // 배열을 넘길때는 사이즈도 함게 넘겨야함. 배열은 시작 주소만 넘어가기 때문에.
//int sumArray(int *pArray, int size);  >> 배열을 넘길때는 주소를 넘기기때문에 pArray[] 대신 *pArray를 써도 된다.


int main(void)
{
    int nums[20];
    srand(time(NULL));
    for(int i = 0; i < 20; i++)
    {
        nums[i] = rand() % 101;
        printf("%d\t", nums[i]);
    }

    int sum = sumArray(nums, sizeof(nums) / sizeof(int));
    printf("SUM : %d\n", sum);

    return 0;
}

int sumArray(int pArray[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += pArray[i];
    }
    return sum;
}