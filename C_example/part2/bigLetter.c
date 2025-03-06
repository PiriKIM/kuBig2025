#include <stdio.h>

//임의의 char를 scanf로 하나 받아서 대문자인지 소문자인지 출력
int main(void)
{
    char alphabet;
    char* str;

    printf("알파벳 하나를 입력하세요: ");
    scanf("%c", &alphabet);

    if(alphabet >= 'A' && alphabet <= 90)
        str = "대문자";
    else if(alphabet >= 'a' && alphabet <= 122)
        str = "소문자";
    else
        str = "아닙니다";

    printf("입력하신 문자 %c 는 알파벳 %s\n", alphabet, str);

    return 0;
}

