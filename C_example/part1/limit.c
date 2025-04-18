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
    
    printf("INT_MIN : %d \t INT_MAX : %d\n", INT_MIN, INT_MAX);
    printf("LONG_MIN : %ld \t LONG_MAX : %ld\n", LONG_MIN, LONG_MAX);
    
    printf("INT_MIN : %d \t INT_MAX + 1 : %d\n", INT_MIN, INT_MAX + 1);
    printf("LONG_MIN : %ld \t LONG_MAX + 1 : %ld\n", LONG_MIN, LONG_MAX + 1);

    return 0;
}

void printHello()
{
    printf("Hello, World from Function\n");
}


