#include <stdio.h>
//문자열에서는 \0 (NULL)이 나오는 순간 끝남.
//문자의 기본값을 NULL.
int main(void)
{
    char *name;
    char namei[20];
    name = namei;
    *name = 'h';
    *(name + 1) = 'e';
    *(name + 2) = 'l';
    *(name + 3) = 'l';
    *(name + 4) = 'o';
    *(name + 5) = 'w';
    *(name + 6) = '\0';
    *(name + 7) = 'l';
    *(name + 8) = 'o';
    *(name + 9) = 'w';
    *(name + 10) = ' ';
    *(name + 11) = ' ';
    *(name + 12) = ' ';
    *(name + 13) = 'l';
    *(name + 14) = 'o';
    *(name + 15) = 'w';
    *(name + 16) = ' ';
    *(name + 17) = 'l';
    *(name + 18) = 'o';
    *(name + 19) = 'w';

    printf("%s\n", name);
    printf("%s\n", name + 7);
    printf("%s\n", namei);
    printf("%s\n", namei + 7);

    return 0;
}