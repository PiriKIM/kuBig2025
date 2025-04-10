#include <stdio.h>  // < > /usr/include/
#include "queue.h"  // " " 현재 디렉토리

int main(void)
{
    Queue q1;
    int queueSize, queueCode, queueValue;

    printf("Enter Queue Size : ");
    scanf("%d", &queueSize);
    initQueue(&q1, queueSize);

    while (1)
    {
        printf("Enter Queue Code (1:push, 2:pop) ");
        scanf("%d", &queueCode);
        if (queueCode == 1)
        {
            printf("Enter Queue Value : ");
            scanf("%d", &queueValue);
            push(&q1, queueValue);
            printf("rear: %d, front: %d\n", q1.rear, q1.front);
        }
        else if (queueCode == 2)
        {
            printf("rear: %d, front: %d, q1 pop(): %d\n", q1.rear, q1.front, pop(&q1));
        }
    }

    cleanupQueue(&q1);

    return 0;
}