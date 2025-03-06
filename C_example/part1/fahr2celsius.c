#include <stdio.h>

int main()
{
    double fahr;
    fahr = 57.2;
    printf("fahrenheit temp : %f \n", fahr);

    int celsius;
    celsius = (fahr - 32) * 5 / 9;
    printf("celsius temp : %d \n", celsius);



    return 0;
}