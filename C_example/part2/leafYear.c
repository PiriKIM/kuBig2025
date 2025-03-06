#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int year;

    while(true)
    {
        printf("년도를 넣으세요: ");
        scanf("%d", &year);
        if(!year)
            break;
        // else if(year % 400 == 0)
        //     printf("%d 년도는 윤년입니다.\n", year);
        // else if(year % 100 == 0)
        //     printf("%d 년도는 평년입니다.\n", year);
        // else if(year % 4 == 0)
        //     printf("%d 년도는 윤년입니다.\n", year);
        // else
        //     printf("%d 년도는 평년입니다.\n", year);

        printf("%d 년도는 %s입니다.\n", year, !(year % 400) ? "윤년" : (!(year % 100) ? "평년" : (!(year % 4) ? "윤년" : "평년")));
    }
    return 0;
}