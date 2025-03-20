#include <avr/interrupt.h>
#include <avr/io.h>

volatile uint8_t ledData = 0x00;
uint8_t timer0Cnt = 0;
ISR(TIMER0_OVF_vect);

int main()
{
    DDRC = 0x0F;

    TCCR0 = _BV(CS02) | _BV(CS01) | _BV(CS00);  // 0x07; // clock select 1024 prescale
    TCNT0 = 112;
    TIMSK = 0x01;
    TIFR |= _BV(TOV0);

    sei();
    while (1)
    {
        if (timer0Cnt == 100)
        {
            ledData++;
            if (ledData > 0x0F)
                ledData = 0;
            timer0Cnt = 0;
        }
        PORTC = ledData;
    }

    return 0;
}

ISR(TIMER0_OVF_vect)
{
    cli();
    TCNT0 = 112; // 113, 114, ... 255 ...  144 -> 0.0025초
    timer0Cnt++;
    sei();
}