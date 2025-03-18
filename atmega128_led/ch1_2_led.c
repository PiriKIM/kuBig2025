#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
        DDRC = 0x03;    // 0011 0, 1을 출력모드로 한다.
        PORTC = 0x0F;   // 1111 0, 1, 2, 3 번을 1(ON) -> 5V 출력시킴.
        _delay_ms(500);

        PORTC = 0x00;   // 0000 0, 1, 2, 3 번을 0(OFF) -> 0V 출력시킴.
        _delay_ms(500);

        PORTC = 0b00000000;
        _delay_ms(1000);
        PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2) | (1 << PC3);     //0x0F
        _delay_ms(1000);
        PORTC = 0b00000000;
        _delay_ms(1000);
        PORTC |= _BV(PC0) | _BV(PC1) | _BV(PC2) | _BV(PC3);             //0x0F
        _delay_ms(1000);
    }

    return 0;
}