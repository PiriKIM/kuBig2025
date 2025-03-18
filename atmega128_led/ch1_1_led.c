#include <avr/io.h>
#include <util/delay.h>

int main()
{
    while(1)
    {
        // PORTC = 0x00;       // 0b00000000
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x01;       // 0b00000001
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x03;       // 0b00000011
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x07;       // 0b00000111
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x0F;       // 0b00001111
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x0E;       // 0b00001110
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x0C;       // 0b00001100
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x08;       // 0b00001000
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x00;       // 0b00000000
        // _delay_ms(100);    // 1초 대기
        // PORTC = 0x0F;       // 0b00001111
        // _delay_ms(100);    // 1초 대기
        DDRA = 0b11111111;//0xFF;    // 출력모드로 한다.
        PORTA = 0x3F;
        _delay_ms(1000);
        PORTA = 0x06;
        _delay_ms(1000);
        PORTA = 0x5B;
        _delay_ms(1000);
        PORTA = 0x4F;
        _delay_ms(1000);
        PORTA = 0x66;
        _delay_ms(1000);
        PORTA = 0x6D;
        _delay_ms(1000);
        PORTA = 0x7D;
        _delay_ms(1000);
        PORTA = 0x27;
        _delay_ms(1000);
        PORTA = 0x7F;
        _delay_ms(1000);
        PORTA = 0x6F;
        _delay_ms(1000);
    }

    return 0;
}