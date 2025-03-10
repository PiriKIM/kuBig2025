// 0~100 중에 랜덤한 수 20개 프린트.
// 정렬 후 프린트.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(void)
{
    int nums[20] = {0};
    srand((unsigned int)time(NULL));
    for(int i = 0; i < 20; i++)
    {
        nums[i] = rand() % 101;
    }

    for(int i = 0; i < 20; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

    //quick sorting 오름차순
    qsort(nums, 20, sizeof(nums[0]), compare);

    for(int i = 0; i < 20; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

    return 0;
}