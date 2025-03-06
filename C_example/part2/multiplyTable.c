#include <stdio.h>

int main(void)
{
    for(int i = 2; i <= 9; i++)
    {
        printf("------%d단 입니다.------\n\n", i);
        for(int j = 2; j <= 9; j++)
            printf("%d X %d = %d\n", i, j, i * j);
        printf("\n");
    }
    printf("-----------------------\n");
    return 0;
}