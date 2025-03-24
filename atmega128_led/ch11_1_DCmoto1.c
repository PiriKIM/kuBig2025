#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD = _BV(PD4) | _BV(PD5);
    DDRB = _BV(PB5);

    TCCR1A = _BV(COM1A1) | _BV(WGM11);
    TCCR1B = _BV(CS11) | _BV(WGM12) | _BV(WGM13);
    // fast PWM 분주비 8 -> 16MHz / 8 = 2MHz
    ICR1 = 800;     // 2MHz : 1초 == 800Hz : x초 -> 
    OCR1A = 320;    // 800 카운트하는데 500 번까지 -> 5V 70%

    while(1)
    {
        PORTD = _BV(PD4);   // M1 정회전 시계방향
        PORTB = _BV(PB5);   // M1 회전
        _delay_ms(5000);
        PORTD = _BV(PD5);   // M1 역회전 반시계방향
        PORTB = _BV(PB5);   // M1 회전
        _delay_ms(5000);
    }

    return 0;
}