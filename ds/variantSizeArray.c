#include <stdio.h>

int main(void)
{
    int size;
    printf("스택 사이즈를 입력하세요: ");
    scanf("%d", &size);

    int array[size];    // C99

    for (int i = 0; i < size; i++)
    {
        array[i] = i + 1;
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}