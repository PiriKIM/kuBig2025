#include <stdio.h>
#include <unistd.h>
#include <wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)   // 자식
    {
        puts("안녕, 나는 자식 프로세스야!!\n");
    }
    else            // 부모
    {
        printf("자식 프로세스 ID : %d \n", pid);
        sleep(30);
    }

    if (pid == 0)   // 자식
    {
        puts("End 자식 프로세스!!\n");
    }
    else            // 부모
    {
        puts("End 부모 프로세스!!\n");
    }

    return 0;
}