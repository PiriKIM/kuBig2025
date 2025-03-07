#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 로또 번호 여섯개 출력.
int main(void)
{
    int lottoNum;
    int randArr[6];
    bool rerandFlag = false;

    srand((unsigned int)time(NULL));            //random setting
    for(int i = 0; i < 6; i++)
    {
        randArr[i] = rand() / (double)RAND_MAX * 45 + 1;    //1~46 중에 랜덤 숫자.
        printf("%d\t", randArr[i]);
    }
    printf("\n");

    return 0;
}