#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// 10짜리 배열을 int로 만들어서 랜덤(0 ~ 100) 합을 구해서 프린트하기.
int main(void)
{
    int arr[10];
    int sum = 0;
    srand(time(NULL));

    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() / (double)RAND_MAX * 100;
        sum += arr[i];
    }
    for (int j = 0; j < 10; j++)
    {
        if(j < 9)
            printf("%d + ", arr[j]);
        else if (j == 9)
            printf("%d = ", arr[j]);
    }
    printf("%d\n", sum);

    return 0;
}