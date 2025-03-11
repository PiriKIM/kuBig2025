#include "random.h"

void my_srand(int s);
int my_rand(void);

int main(void)
{
    my_srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        int num = my_rand();
        printf("%d\t", num);
    }
    printf("\n");

    return 0;
}

