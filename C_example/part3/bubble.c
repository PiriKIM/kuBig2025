// 0~100 중에 랜덤한 수 20개 프린트.
// 정렬 후 프린트.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    //bubble sorting 오름차순
    for(int i = 20 - 1; i >= 1; --i)
    {// 1은 각 스텝에 비교할 횟수
        for(int j = 0; j < i; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 20; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

//bubble sorting 내림차순
    for(int i = 20 - 1; i >= 1; --i)
    {// 1은 각 스텝에 비교할 횟수
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[j + 1])
            {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < 20; i++)
    {
        printf("%d\t", nums[i]);
    }
    printf("\n");

    return 0;
}