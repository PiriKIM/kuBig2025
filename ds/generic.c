#include <stdio.h>
#include <string.h>

int main(void)
{
    int a = 100;
    int b;
    
    b = 0;
    printf("a: %d\tb: %d\n", a, b);

    b = a;
    printf("a: %d\tb: %d\n", a, b);

    int isEqualAB = (a == b);
    printf("a == b : %d\n",isEqualAB);

    int c = 100;
    int d;
    
    memset(&d, 0, sizeof(int));
    printf("c: %d\td: %d\n", c, d);

    int isEqualCD = !memcmp(&c, &d, sizeof(int));
    printf("c == d : %d\n",isEqualCD);

    memcpy(&d, &c, sizeof(int));
    printf("c: %d\td: %d\n", c, d);

    // if (memcmp(&c, &d, sizeof(int)) == 0)
    //     isEqualCD = 1;
    // else
    //     isEqualCD = 0;
    // int isEqualCD = (memcmp(&c, &d, sizeof(int)) == 0) ? 1 : 0;
    isEqualCD = !memcmp(&c, &d, sizeof(int));
    printf("c == d : %d\n",isEqualCD);

    return 0;
}