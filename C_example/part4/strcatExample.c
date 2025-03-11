#include <stdio.h>
#include <string.h>

int main(void)
{
    const char *str1 = "hello, world";
    char str2[] = "stack char array";
    int str1Len = strlen(str1);     //NULL은 갯수에 미포함.
    int str2Len = strlen(str2);
    printf("str1Len : %d\tstr2Len : %d\n", str1Len, str2Len);

    char str3[40];
    strcpy(str3, str1);
    str3[0] = 'H';
    printf("%s\n", str3);
    // strcmp >> 두 문자열을 앞에서부터 차례로 비교해나가면서
    //          처음 만나는 서로 다른 문자의 아스키코드 값의 차를 반환
    //          두 문자열이 동일하면 0을 반환하게 됨.
    printf("strcmp(str1, str2) : %d\n", strcmp(str1, str2));    // h - s = 104 - 115 = -11
    printf("strcmp(str2, str1) : %d\n", strcmp(str2, str1));    // s - h = 115 - 104 = 11
    printf("strcmp(str1, str3) : %d\n", strcmp(str1, str3));    // h - H = 104 - 72 = 32
    printf("strcmp(str3, str1) : %d\n", strcmp(str3, str1));    // H - h = 72 - 104 = -32

    strcat(str3, " & ");
    strcat(str3, str2);
    printf("%s\n", str3);

    return 0;
}