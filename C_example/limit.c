#include <stdio.h>
#include <limits.h>

void printHello();

//int main(int argc, char* argv[]) //인수를 받을 때
int main(void)
{
    printHello();
    printf("Hello, World from Main\n");
    printf("char_bit : %d\n", CHAR_BIT);
    printf("char_max : %d\n", CHAR_MAX);
    
    return 0;
}

void printHello()
{
    printf("Hello, World from Function\n");
}


