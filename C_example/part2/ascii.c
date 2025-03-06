#include <stdio.h>
// 0 ~ 127 아스키 코드를 출력하세요.
// 이중 for문으로 만드세요.
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
// 8 줄 출력
int main(void)
{
    char ascii;

    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            ascii = i * 16 + j;
            printf("%d : %c\t", ascii, ascii);
        }
        printf("\n");
    }

    return 0;
}