// 볼드, 이탈릭, 쉐도우, 언더라인을 표현하는 변수를 만들어라.
// 비트 자리 1: 볼드, 2: 이탈릭, 3: 쉐도우, 4: 언더라인
#include <stdio.h>

int main(void)
{
    unsigned char attr; //8비트이므로 8개 속성을 표현 가능.
    //속성이 4가지여도 4비트보다는 8비트가 적절.
    //비트 연산을 할때는 unsigned로 사용.
    attr = attr ^ attr; //모두 0
    attr = attr | 0b00000001;   //attr 볼드로 설정
    printf("attr : 0x%02x\n", attr);
    attr = attr | (0b00000010 | 0b00000100);    //attr 이탈릭, 쉐도우 추가
    printf("attr : 0x%02x\n", attr);
    attr = attr & (~0b00000001);    //attr 볼드 해제
    printf("attr : 0x%02x\n", attr);

    return 0;
}