#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRC = 0x07;

    while(1)
    {
        PORTC = 0b00000111;
        _delay_ms(300);
        PORTC = 0b00000011;
        _delay_ms(300);
        PORTC = 0b00000001;
        _delay_ms(300);
        PORTC = 0b00000110;
        _delay_ms(300);
        PORTC = 0b00000100;
        _delay_ms(300);
        PORTC = 0b00000101;
        _delay_ms(300);
        PORTC = 0b00000010;
        _delay_ms(300);
        PORTC = 0b00000000;
        _delay_ms(300);
    }
}