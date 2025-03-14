#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *str1 = "apple";
    char str2[] = "apple";
    char *str3;
    str3 = (char *)malloc(sizeof(char) * 6);
    strcpy(str3, str2);
    printf("apple : %s\taddress : %p\n", "apple", "apple");
    // >> 리터럴 상수도 데이터 영역이므로 데이터 영역에 같은 값이있으면 그 주소를 따라감.
    printf("str1 : %s\taddress : %p\n", str1, str1);    //데이터영역
    printf("str2 : %s\taddress : %p\n", str2, str2);    //스택영역
    printf("str3 : %s\taddress : %p\n", str3, str3);    //힙영역

    char *pChar1;
    pChar1 = str3;

    free(str3);

    printf("pChar1 : %s\taddress : %p\n", pChar1, pChar1);    //힙영역

    return 0;
}