#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1)
    {
        perror("shm_open");
        exit(1);
    }

    ftruncate(shm_fd, 4096);    // 4Kbyte
    char *shm = mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED)
    {
        perror("mmap");
        exit(1);
    }

    strcpy(shm, "Hello shared memory FROM process 1!\n");

    char temp[10];
    scanf("%s", temp);

    munmap(shm, 4096);
    shm_unlink("/myshm");

    return 0;
}