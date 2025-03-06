#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// 숫자를 입력 받아서 양수, 제로, 음수를 출력하는 프로그램
// if else 구문으로 만드세요.
// printf는 한 번 만 쓰세요.
int main(int argc, char* argv[])
{
    char* str;
    int num;
    if (argc < 2)
    {
        printf("인자를 하나 넣어서 실행하세요.\n");
        return 0;
    }
    num = atoi(argv[1]);

    if (num > 0)
    {
        str = "양수";
    }
    else if (num < 0)
    {
        str = "음수";
    }
    else
    {
        str = "제로";
    }

    printf("숫자 %d 는 %s입니다.\n", num, str);

    return 0;
}