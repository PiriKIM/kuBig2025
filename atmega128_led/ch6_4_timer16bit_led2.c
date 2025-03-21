// LED를 0.3초 간격으로 좌우로 움직이세요.
// timer3 를 써서 인터럽트로 구현하세요.
// 분주비는 256을 쓰세요. 책 318 페이지.
// 인터럽트가 0.3초 마다 일어나게 하세요.
#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8_t ledData = 0x01;
volatile uint8_t direction = 1;

int main(void)
{
    DDRC = 0x0F;

    TCCR3A = 0x00;
    TCCR3B = _BV(CS32);     // 분주비 1 16MHz >> 16000000 / 65536 = 244.144 Hz
    // 분주비 256 16MHz >> 16000000 / 256 = 62500 >> 16us * 18750 = 0.3s
    ETIMSK = _BV(TOIE3);    // ETIMSK 인거 주의!!!!!!!!!!!
    TCNT3 = 46786;
    sei();      // 전역 인터럽트 허용

    while(1)
        PORTC = ledData;

    return 0;
}

ISR(TIMER3_OVF_vect)
{
    cli();
    TCNT3 = 46786;
    if (ledData > 0x04)
        direction = 0;
    if (ledData == 1)
    {
        direction = 1;
        ledData = 1;
    }
    if (direction)
        ledData <<= 1;
    else
        ledData >>= 1;

    PORTC = ledData;
    sei();
}

