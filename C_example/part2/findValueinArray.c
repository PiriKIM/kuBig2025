//10개짜리 배열을 랜덤으로 0~100 만들어서 int를 하나 scanf로 받는다.
//같은 원소가 있는지 index가 몇 번째인지 출력하시오.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int arr[10];
    int num;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() / (double)RAND_MAX * 10;
        printf("%d\t", arr[i]);
    }
    printf("\n 찾을 숫자 하나를 입력하세요: ");
    scanf("%d", &num);
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == num)
            printf("입력한 숫자와 같은 index는 %d 입니다.\n", i);
    }

    return 0;
}