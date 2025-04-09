#include <stdio.h>

void my_strcpy0(char *des, const char *src)
{
    int i;
    for (i = 0; src[i] != '\0'; i++)
    {
        des[i] = src[i];
    }
    des[i] = '\0';
}

void my_strcpy(char *des, const char *src)
{
    while (*des++ = *src++)
        ;
}

int main(void)
{
    int a, b, c;
    a = 300;
    b = 200;
    c = 100;
    printf("a: %d, b: %d, c: %d\n", a, b, c);
    a = b = c;
    printf("a: %d, b: %d, c: %d\n", a, b, c);

    char *str = "hello, world!";
    char str2[100];
    char str3[100];

    my_strcpy0(str2, str);
    printf("str2: %s\n", str2);

    my_strcpy(str3, str);
    printf("str3: %s\n", str3);

    return 0;
}