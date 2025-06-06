#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

void *thread_main(void *arg);   // * 함수 포인터로 쓰겠다는 명시. * 안써도 함수는 자체가 포인터!!!

int main()
{
    pthread_t t_id;
    int thread_param = 5;
    void *thr_ret;

    pthread_create(&t_id, NULL, (void *)thread_main, (void *)&thread_param);
    // 쓰레드 동작!! (백그라운드)
    pthread_join(t_id, &thr_ret);   // 쓰레드가 리턴될 때까지 대기!!

    for (int i = 0; i < 10; ++i)
    {
        sleep(1);
        puts("running main()");
    }

    printf("쓰레드에서 받아온 메세지 : %s \n", (char *)thr_ret);
    free(thr_ret);

    return 0;
}

void *thread_main(void *arg)
{
    int cnt = *((int *)arg);
    char *msg = (char *)malloc(sizeof(char) * 50);
    strcpy(msg, "Hello, I'am from thread--- \n");
    for (int i = 0; i < cnt; ++i)
    {
        sleep(1);
        puts("running thread_main()");
    }

    return msg;
}