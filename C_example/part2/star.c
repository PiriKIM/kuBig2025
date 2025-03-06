#include <stdio.h>
// 별표를 5줄 하나씩 늘어나는 모양을 출력하세요.
// 별표를 피라미드 모양으로 출력하세요.

int main(void)
{
    int num;
    printf("1이상의 숫자를 입력하세요: ");
    scanf("%d", &num);

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("-----피라미드-----\n");

    for(int k = 0; k < num; k++)
    {
        for(int l = 0; l < num - k - 1; l++)
        {
            printf(" ");
        }
        for(int m = 0; m < 2 * k + 1; m++)
        {
            printf("*");
        }
        printf("\n");
    }

    printf("-----다이아몬드-----\n");
    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j < num - i - 1; j++)
        {
            printf(" ");
        }
        for(int k = 0; k < 2 * i + 1; k++)
        {
            printf("*");
        }
        printf("\n");
    }
    for(int l = 0; l < num - 1; l++)
    {
        for(int m = 0; m < l + 1; m++)
        {
            printf(" ");
        }
        for(int n = 0; n < 2 * (num - l - 2) + 1; n++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
