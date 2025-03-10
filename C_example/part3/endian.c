//BigEndian, LittleEndian
// 운영체제마다 다름
// 통신에서는 BigEndian 통일.
#include <stdio.h>

int main(void)
{
    int a = 0x12345678;
    char *pA;
    pA = (char *)&a;
    printf("*pA :0x%x\n", *pA);
    // 12이 나오면 빅엔디안, 78가 나오면 리틀엔디안.
    // 78나오므로 리틀엔디안 >> 인텔CPU

    return 0;
}