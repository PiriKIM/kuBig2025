#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define THREAD_NUM 5

void *thread_main(void *arg);   // * 함수 포인터로 쓰겠다는 명시. * 안써도 함수는 자체가 포인터!!!

int main()
{
    pthread_t t_id[THREAD_NUM];
    void *thr_ret;
    int range[5][2] = {{1, 5}, {6, 10}, {11, 15}, {16, 20}, {21, 25}};

    for (int i = 0; i < THREAD_NUM; ++i)
        pthread_create(&t_id[i], NULL, (void *)thread_main, (void *)&range[i]);
    // 쓰레드 동작!! (백그라운드)

    for (int i = 0; i < THREAD_NUM; ++i)
    {
        pthread_join(t_id[i], &thr_ret);   // 쓰레드가 리턴될 때까지 대기!!
        printf("쓰레드에서 받아온 메세지 : %s \n", (char *)thr_ret);
    }

    printf("쓰레드 끝!! 메인 시작!! \n");

    for (int i = 0; i < 10; ++i)
    {
        sleep(1);
        puts("running main()");
    }

    free(thr_ret);

    return 0;
}

void *thread_main(void *arg)
{
    int start = ((int *)arg)[0];
    int end = ((int *)arg)[1];
    char *msg = (char *)malloc(sizeof(char) * 50);
    strcpy(msg, "Hello, I'am from thread--- \n");
    for (int i = start; i < end; ++i)
    {
        sleep(1);
        printf("running thread_main(), %d\n", i);
    }

    return msg;
}