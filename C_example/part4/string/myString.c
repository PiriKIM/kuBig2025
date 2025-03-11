#include "myString.h"

int my_strlen(const char *s)
{
    int len = 0;

    while(1)
    {
        if(*(s + len) == '\0')
            break;
        else
            ++len;
    }
    
    return len;
}

void my_strcpy(char *des, const char *src)
{
    int cnt = 0;

    while(1)
    {
        if(*(src + cnt) == '\0')
        {
            *(des + cnt) = '\0';
            break;
        }
        else
        {            
            *(des + cnt) = *(src + cnt);
            ++cnt;
        }
    }
}

int my_strcmp(const char *s1, const char *s2)
{
    int cnt = 0;
    int cmp = 0;

    while(1)
    {
        cmp = *(s1 + cnt) - *(s2 + cnt);
        if(*(s1 + cnt) == '\0' || *(s2 + cnt) == '\0')
            break;
        else if(cmp != 0)
            break;
        else
            ++cnt;        
    }

    return cmp;
}

void my_strcat(char *des, const char *src)
{
    int desLen = my_strlen(des);
    int srcLen = my_strlen(src);

    for(int i = 0; i < srcLen; i++)
    {
        *(des + desLen + i) = *(src + i);
    }

    *(des + desLen + srcLen) = '\0';
}