#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char cArr[4] = "Aa9";
    int *pi;
    pi = cArr;

    printf("%s\n", cArr);
    for (int i = 0; i < 4; i++)
    {
        printf("cArr[%d]: %d\t", i, cArr[i]);
    }
    printf("\n0x%08x\n", *pi);
    printf("%d\n", *pi);
    printf("%p\n", pi);

    return 0;
}