// n(MAX) 개의 숫자를 배열로 만들어서[랜덤] MAXC까지 평균을 소수점 2자리까지 출력.

// VLA(variable length array) - C에서는 허용하지만 C++에서는 안됨. 추천하지않음.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 23
#define MAXC 100

int main(void)
{
    srand((unsigned int)time(NULL));
    int max_input;
    printf("배열의 크기를 넣으세요 : ");
    scanf("%d", &max_input);
    int scores[max_input];
    int sum = 0;
    double average;
    for (int i = 0; i < max_input; i++)
    {
        scores[i] = rand() % (MAXC + 1);
        printf("%d,\t", scores[i]);
        sum += scores[i];
    }
    average = (double)sum / max_input;

    printf("평균은 %.2f 입니다.\n", average);

    return 0;
}