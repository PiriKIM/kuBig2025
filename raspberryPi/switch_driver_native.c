#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buf[4];
    fd = open("/dev/switch_driver", O_RDWR);
    if (fd < 0)
    {
        printf("driver open fail\n");
        return -1;
    }
    for (int i = 0; i < 10; ++i)
    {
        read(fd, &buf, 4);
        printf("SW1 : %d, SW2 : %d, SW3 : %d, SW4 : %d\n", buf[0], buf[1], buf[2], buf[3]);
        sleep(1);
    }
    close(fd);
    return 0;
}