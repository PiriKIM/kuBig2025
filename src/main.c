#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

int main()
{
    lcdInit();
    lcdClear();
    char lcdBuffer[17];

    unsigned char switch_flag = 0;
    DDRE = 0x00;    // 8개의 핀을 모두 인풋 모드
    PORTE = 0x00;   // 출력 - 풀업을 설정한다.
    DDRC = 0x0F;    // LED 4개 모두 아웃풋 모드
    PORTC = 0x00;   // LEC 4개 모두 OFF
    // PIN_E
    while(1)
    {

    }

    return 0;
}