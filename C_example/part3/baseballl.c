// 숫자 3개를 만드세요.[0 ~ 9 랜덤 & 서로 다른 숫자]
// 숫자 3개를 입력 받으세요.
// 위치와 숫자가 같은면 strike + 1
// 위치가 다르지만 숫자가 같으면 ball + 1
// 모든 데이터의 위치와 숫자가 동일하면 성공.
// 시도 횟수를 출력하는 프로그램을 만드세요.
// 받아적은 버전.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void)
{
    int question[3];
    int answer[3];
    srand((unsigned int)time(NULL));

    question[0] = rand() % 10;

    do
    {
        question[1] = rand() % 10;
    } while (question[0] == question[1]);

    do
    {
        question[2] = rand() % 10;
    } while (question[0] == question[2] || question[1] == question[2]);

    printf("%d %d %d\n", question[0], question[1], question[2]);

    while(true)
    {
        printf("숫자 세 개를 입력해 주세요 : ");
    }

}