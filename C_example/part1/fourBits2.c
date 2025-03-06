// 볼드, 이탈릭, 쉐도우, 언더라인을 표현하는 변수를 만들어라.
// 비트 연산
#include <stdio.h>

#define BOLD        0x01
#define ITALIC      (0x01 << 1)     //0x02
#define SHADOW      (0x01 << 2)     //0x04
#define UNDERLINE   (0x01 << 3)     //0x08
//define할 때는 괄호를 해줘야한다.

void printAttrib(unsigned char attr);

int main(void)
{
    unsigned char attr; //8비트이므로 8개 속성을 표현 가능.
    //속성이 4가지여도 4비트보다는 8비트가 적절.
    //비트 연산을 할때는 unsigned로 사용.
    attr = attr ^ attr; //모두 0
    attr = attr | BOLD;   //attr 볼드로 설정
    printAttrib(attr);
    //printf("attr : 0x%02x\n", attr);
    attr = attr | (ITALIC | SHADOW);    //attr 이탈릭, 쉐도우 추가
    printAttrib(attr);
    //printf("attr : 0x%02x\n", attr);
    attr = attr & (~BOLD);    //attr 볼드 해제
    printAttrib(attr);
    attr = attr | UNDERLINE;   //attr 언더라인으로 설정
    attr = attr & (~SHADOW);    //attr 이탈릭 해제
    printAttrib(attr);
    //printf("attr : 0x%02x\n", attr);

    return 0;
}

void printAttrib(unsigned char attr)
{
    printf("BOLD : %d\n", (attr & BOLD));
    printf("attr : 0x%02x\n", (attr & BOLD));
    printf("ITALIC : %d\n", (attr & ITALIC) >> 1);
    printf("attr : 0x%02x\n", (attr & ITALIC));
    printf("SHADOW : %d\n", (attr & SHADOW) >> 2);
    printf("attr : 0x%02x\n", (attr & SHADOW));
    printf("UNDERLINE : %d\n", (attr & UNDERLINE) >> 3);
    printf("attr : 0x%02x\n", (attr & UNDERLINE));
    printf("-------------------------------\n");
}