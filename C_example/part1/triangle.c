#include <stdio.h>

int main(void)
{
    double length;
    double height;
    double area;
    //%f는 float에 사용, %lf는 double에 사용
    printf("Enter triangle's length : ");
    scanf("%lf", &length);
    printf("Enter triangle's height : ");
    scanf("%lf", &height);
    area = length * height / 2.0;
    printf("triangle's area is : %.2f\n", area);

    return 0;
}