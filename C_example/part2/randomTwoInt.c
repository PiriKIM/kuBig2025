#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// 두 난수(0~10)를 발생시켜서 비교하기.
// 10까지이 수를 비교해서 같아질때까지 반복.
int main(void)
{
    int a, b, i;
    double rand1, rand2;

    i = 0;

    while(true)
    {
        i++;
        srand((unsigned int)time(NULL));            //random setting
        rand1 = rand() / (double)RAND_MAX * 10;    //0부터 곱한 숫자까지 중에 랜덤 숫자.
        rand2 = rand() / (double)RAND_MAX * 10;
    
        a = rand1;
        b = rand2;
    
        printf("0~100사이의 랜덤한 숫자: %f\n", rand1);
        printf("0~100사이의 랜덤한 숫자: %f\n", rand2);
        printf("%d > %d : %s\n", a, b, a > b ? "true" : "false");
        printf("%d < %d : %s\n", a, b, a < b ? "true" : "false");
        printf("%d == %d : %s\n", a, b, a == b ? "true" : "false");
        printf("%d != %d : %s\n", a, b, a != b ? "true" : "false");
    
        if(a == b)
        {
            printf("%d번 실행\n", i);
            break;
        }
    }
    
    return 0;
}