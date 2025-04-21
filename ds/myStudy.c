#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char a[] = "HelloA";
    char b[] = "Helloa";
    char c[] = "Str";

    printf("%d\n", strcmp(a, b));

    // strcpy(b, c);

    // printf("%s\n", b);

    strncpy(b, c, 2);
    printf("%s\n", b);
    strncpy(a, c, 3);
    printf("%s\n", a); 

    printf("%s\n", strchr(c, 'r'));
    // printf("%c\n", strchr(c, 'r'));
    // printf("%d\n", strchr(c, 'r'));
    printf("%p\n", strchr(c, 'r'));

    printf("%d %d %d\n", isalpha('?'), isalpha('b'), isalpha('B'));
    printf("%d %d %d\n", isdigit('0'), islower('a'), isupper('A'));
    printf("%d %d %d\n", isxdigit('5'), isxdigit('a'), isxdigit('A'));
    printf("%d %d %d\n", isalnum('5'), isalnum('a'), isalnum('A'));

    const int num = 100;
    int ber = 200;

    printf("%d %d\n", num, ber);

    // num = ber;

    ber = num;

    printf("%d %d\n", num, ber);

    return 0;
}