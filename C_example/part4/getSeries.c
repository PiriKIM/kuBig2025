#include <stdio.h>

int main(void)
{
    char ch;
    char str[100];

    printf("문자를 입력하세요: ");
    ch  = getc(stdin);
    printf("입력한 문자는 %c 입니다.", ch);
    fflush(stdin);      //fflush로는 입력 버퍼가 비워지지않음.
    scanf("%c", &ch);
    printf("입력한 문자는 %c 입니다.", ch);
    printf("\n문자열을 입력하세요: ");
    while ((ch = getchar()) != '\n' && ch != EOF);
    scanf("%s", str);
    printf("입력한 문자열은 %s 입니다.\n", str);

    return 0;
}