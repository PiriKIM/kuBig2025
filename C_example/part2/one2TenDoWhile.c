#include <stdio.h>
#include <stdbool.h>

// 1 ~ 10까지 do while로 출력하기
int main(void)
{
    int i = 0;
    do
    {
        ++i;
        printf("%d 번 출력합니다.\n", i);
    } while (i < 10);
    
    return 0;
}