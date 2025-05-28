#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    int shm_fd = shm_open("/myshm", O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("shm_open (reader)");
        exit(1);
    }

    char *shm = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED) {
        perror("mmap (reader)");
        exit(1);
    }

    printf("<공유 메모리에서 읽은 내용>\n%s\n", shm);
    printf("size: %ld, strlen: %ld\n", sizeof(shm), strlen(shm));

    // for (int i = 0; shm[i] != '\0'; ++i)
    // {
    //     printf("shm[%d]: %d\n", i, shm[i]);
    // }

    munmap(shm, 4096);
    close(shm_fd);
    return 0;
}
