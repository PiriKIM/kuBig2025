// 1 과 9 사이의 숫자인지 확인해서 맞으면 1 틀리면 0을 출력.
#include <stdio.h>

int main(void)
{
    int number;
    int compare;

    printf("1과 9사이의 정수 중 하나 입력 : ");
    scanf("%d", &number);

    compare = number >= 1 && number <= 9;

    printf("1 <= %d <= 9 : %d\n", number, compare);

    return 0;
}