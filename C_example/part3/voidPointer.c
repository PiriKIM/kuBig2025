#include <stdio.h>

int main(void)
{
    int i = 100;
    double d = 3.141592;

    void *p;

    //p 로 i 가리키기
    p = &i;
    printf("p 의 주소값은 : %p\n", p);
    printf("*p 의 값은 : %d\n", *(int *)p);

    //p 로 d 가리키기
    p = &d;
    //*p = 6.381      //void 포인터의 역참조는 안된다.
    *(double *)p = 7.9391;
    printf("p 의 주소값은 : %p\n", p);
    printf("*p 의 값은 : %f\n", *(double *)p);

    return 0;
}