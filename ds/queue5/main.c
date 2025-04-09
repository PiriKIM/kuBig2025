#include <stdio.h>  // < > /usr/include/
#include "queue.h"  // " " 현재 디렉토리

int main(void)
{
    Queue q1, q2;

    initQueue(&q1, 10, sizeof(int));
    initQueue(&q2, 100, sizeof(double));

    int i;
    int re;
    i = 100;    push(&q1, &i);
    i = 200;    push(&q1, &i);
    pop(&q1, &re);    printf("q1 1st pop(): %d\n", re);
    i = 300;    push(&q1, &i);
    pop(&q1, &re);    printf("q1 2nd pop(): %d\n", re);
    pop(&q1, &re);    printf("q1 3rd pop(): %d\n", re);

    double d;
    double re2;
    d = 1.1;    push(&q2, &d);
    d = 2.2;    push(&q2, &d);
    pop(&q2, &re2);    printf("q2 1st pop(): %f\n", re2);
    d = 3.3;    push(&q2, &d);
    pop(&q2, &re2);    printf("q2 2nd pop(): %f\n", re2);
    pop(&q2, &re2);    printf("q2 3rd pop(): %f\n", re2);

    cleanupQueue(&q1);
    cleanupQueue(&q2);

    return 0;
}