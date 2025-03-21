#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8_t ledData = 0x00;
volatile uint8_t timer1Cnt = 0;

int main(void)
{
    DDRC = 0x0F;

    TCCR1A = 0x00;
    TCCR1B = _BV(CS10) | _BV(CS12);     // 분주비 1 16MHz >> 16000000 / 65536 = 244.144 Hz
    // 분주비 1024 16MHz >> 16000000 / 1024 = 15625 >> 65535 - 15625 = 49910
    TIMSK = _BV(TOIE1);
    TCNT1 = 49910;
    sei();      // 전역 인터럽트 허용

    while(1)
        ;

    return 0;
}

ISR(TIMER1_OVF_vect)
{
    cli();
    TCNT1 = 49910;
    PORTC = ledData;
    ledData++;
    if(ledData > 0x0F)
        ledData = 0;
    sei();
}