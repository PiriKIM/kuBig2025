#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_NAME "/myqueue"
#define MAX_MSG_SIZE 128

int main()
{
    mqd_t mq = mq_open(QUEUE_NAME, O_WRONLY);

    char buffer[] = "Hello from client!!";

    mq_send(mq, buffer, strlen(buffer) + 1, 0);
    printf("서버로 보낸 메세지: %s\n", buffer);

    mq_close(mq);

    return 0;
}