#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main() {
    if (shm_unlink("/myshm") == -1) {
        perror("shm_unlink 실패");
        return 1;
    }

    printf("공유 메모리가 성공적으로 제거되었습니다.\n");
    return 0;
}
