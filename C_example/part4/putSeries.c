#include <stdio.h>

int main(void)
{
    FILE *fp;
    fp = fopen("output.txt", "w");
    if(fp == NULL)
    {
        printf("파일 열기 실패");
        return 1;
    }

    putc('A', fp);      //파일에
    putc('A', stdout);  //화면에
    fputc('B', fp);      //파일에
    fputc('B', stdout);  //화면에
    // gets() >> deprecicate 지원 종료
    fputs("puts로 문자가 간다.\n", fp);
    fputs("puts로 문자가 간다.\n", stdout);
    fprintf(fp, "printf로 문자가 간다.\n");
    fprintf(stdout, "printf로 문자가 간다.\n");
    // EOF == -1;
    fclose(fp);

    return 0;
}