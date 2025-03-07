// 10개의 랜덤한 0~100  배열을 만들고 가장 높은 값을 출력하시오.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[10];
    int max = 0;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() / (double)RAND_MAX * 100;
        printf("%d\t", arr[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    printf("중에서 가장 큰 수는 : %d\n", max);

    return 0;
}