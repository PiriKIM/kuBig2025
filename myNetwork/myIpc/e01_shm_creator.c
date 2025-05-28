#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>

int main() {
    int shm_fd = shm_open("/myshm", O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("shm_open");
        exit(1);
    }

    ftruncate(shm_fd, 4096);  // 4KB 크기 지정

    char *shm = mmap(0, 4096, PROT_WRITE | PROT_READ, MAP_SHARED, shm_fd, 0);
    if (shm == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }

    const char *initial_msg = "초기 메시지: 공유 메모리가 생성되었습니다.";
    strcpy(shm, initial_msg);

    printf("공유 메모리가 생성되었고, 초기화되었습니다.\n");
    printf("종료하려면 아무 키나 누르세요...\n");
    getchar();  // 프로그램 종료 지연 (테스트 용)

    munmap(shm, 4096);
    close(shm_fd);

    // 공유 메모리 삭제는 하지 않음
    // cleaner 로 분리함
    return 0;
}
