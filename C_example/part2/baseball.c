// 숫자 3개를 만드세요.[0 ~ 9 랜덤 & 서로 다른 숫자]
// 숫자 3개를 입력 받으세요.
// 위치와 숫자가 같은면 strike + 1
// 위치가 다르지만 숫자가 같으면 ball + 1
// 모든 데이터의 위치와 숫자가 동일하면 성공.
// 시도 횟수를 출력하는 프로그램을 만드세요.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int randNum[3];
    int inputNum[3];
    int strike = 0, ball = 0;
    int tryNum = 1;
    
    srand((unsigned int)time(NULL));

    for(int i = 0; i < 3; i++)
    {
        randNum[i] = rand() % 10;
        printf("%d\t", randNum[i]);
    }

    while(randNum[0] == randNum[1] || randNum[1] == randNum[2] || randNum[2] == randNum[0])
    {
        printf("\n");
        for(int i = 0; i < 3; i++)
        {
            randNum[i] = rand() % 10;
            printf("%d\t", randNum[i]);
        }
    }

    printf("\n0~9사이 숫자 3개를 중복없이 순서 상관없이 입력하세요 : ");
    scanf("%d %d %d", &inputNum[0], &inputNum[1], &inputNum[2]);

    for(int i = 0; i < 3; i++)
    {
        if(inputNum[i] == randNum[i])
            strike++;
        for(int j = 0; j < 3; j++)
        {
            if(inputNum[i] == randNum[j] && i != j)
                ball++;
        }
    }

    if(strike == 3)
    {
        printf("성공입니다!!!\n");
    }
    else
    {
        while(strike != 3)
        {
            printf("%d strike, %d ball 입니다. 다시 도전하세요.\n", strike, ball);
            tryNum++;
            strike = 0;
            ball = 0;
            printf("0~9사이 숫자 3개를 중복없이 순서 상관없이 입력하세요 : ");
            scanf("%d %d %d", &inputNum[0], &inputNum[1], &inputNum[2]);
        
            for(int i = 0; i < 3; i++)
            {
                if(inputNum[i] == randNum[i])
                    strike++;
                for(int j = 0; j < 3; j++)
                {
                    if(inputNum[i] == randNum[j] && i != j)
                        ball++;
                }
            }
        }
        printf("성공입니다!!!\n");
    }

    printf("도전 횟수 : %d\n", tryNum);

    return 0;
}