#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

#define SHM_SIZE 4096

int main() {
    int shm_fd = shm_open("/myshm", O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open (append writer)");
        exit(1);
    }

    char *shm = mmap(0, SHM_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        close(shm_fd);
        exit(1);
    }

    size_t current_len = strlen(shm);
    if (current_len >= SHM_SIZE - 1) {
        fprintf(stderr, "공유 메모리에 더 이상 쓸 공간이 없습니다.\n");
        munmap(shm, SHM_SIZE);
        close(shm_fd);
        return 1;
    }

    char input[256];
    printf("공유 메모리에 이어서 쓸 문자열 입력: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // 개행 제거

    // 구분자 포함 (개행 문자 추가)
    char with_newline[258];  // 256 + \n + \0
    snprintf(with_newline, sizeof(with_newline), "\n%s", input);

    if (current_len + strlen(with_newline) >= SHM_SIZE - 1) {
        fprintf(stderr, "입력한 데이터가 공유 메모리를 초과합니다.\n");
        munmap(shm, SHM_SIZE);
        close(shm_fd);
        return 1;
    }

    strcat(shm, with_newline);  // 개행 포함 이어쓰기
    printf("입력한 내용을 공유 메모리에 추가했습니다.\n");

    munmap(shm, SHM_SIZE);
    close(shm_fd);
    return 0;
}
