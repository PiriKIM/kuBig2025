#include "myString.h"

int main(void)
{
    char *str = "wonderful C class";
    int len = my_strlen(str);
    printf("length of str : %d\n", len);

    char str2[40];
    my_strcpy(str2, str);
    printf("%s\n", str2);

    if(my_strcmp(str2, str) == 0)
        printf("두 문자열의 내용은 같다.\tResult : %d\n", my_strcmp(str2, str));
    else
        printf("두 문자열의 내용은 다르다.\tResult : %d\n", my_strcmp(str2, str));


    str2[9] = 'C';
    str2[10] = '+';
    str2[11] = '+';
    if(my_strcmp(str2, str) == 0)
        printf("두 문자열의 내용은 같다.\tResult : %d\n", my_strcmp(str2, str));
    else
        printf("두 문자열의 내용은 다르다.\tResult : %d\n", my_strcmp(str2, str));
    
    my_strcat(str2, "----");
    my_strcat(str2, str);
    printf("%s\n", str2);

    return 0;
}