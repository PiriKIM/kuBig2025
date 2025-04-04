#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int fd;
    char buf_led[4] = {0};
    char buf_sw[4];
    fd = open("/dev/led_switch_driver", O_RDWR);

    if (fd < 0)
    {
        printf("driver open fail\n");
        return -1;
    }

    while (1)
    {
        for (int i = 0; i < 10; ++i)
        {
            read(fd, &buf_sw, 4);
            printf("SW1 : %d, SW2 : %d, SW3 : %d, SW4 : %d\n", buf_sw[0], buf_sw[1], buf_sw[2], buf_sw[3]);
            for (int i = 0; i < 4; ++i)
                buf_led[i] = buf_sw[i];
            write(fd, &buf_led, 4);
            sleep(1);
        }
    }

    close(fd);

    return 0;
}