#include <stdlib.h>
#include <stdio.h>

// 60 이상이면 합격을 출력
int main(int argc, char* argv[])
{
    printf("%d\n", argc);
    if(argc < 2)
    {
        printf("인자를 하나 넣어서 실행하세요.\n");
        return 0;
    }
    // printf("%s\n", argv[0]);
    // printf("%s\n", argv[1]);
    printf("score: %s --- %s\n", argv[1], atoi(argv[1]) >= 60 ? "PASS" : "FAIL");

    return 0;
}