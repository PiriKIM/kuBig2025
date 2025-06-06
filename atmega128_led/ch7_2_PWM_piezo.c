#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

uint16_t doReMi[8] = {523, 587, 659, 698, 783, 880, 987, 1046};
uint8_t piano = 0;

int main(void)
{
    // PB7 핀 피에조 -> OCR1C
    DDRB = _BV(PB7);    // 7번 출력 설정

    TCCR1A = _BV(COM1C1) | _BV(WGM11);  //COM 10 설정 -> clear on compare
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS00);  // 분주비 1 -> No Prescale, fast PWM
    // TCCR1C = 0x00;

    sei();  // 전역 인터럽트 허용

    while (1)
    {
        ICR1 = 14745600 / doReMi[piano];    // 주파수만큼 duty cycle을 설정 하겠다.
        OCR1C = ICR1 / 2;   // 절반을 on 시키겠다.
        piano++;
        if(piano > 7)
            piano = 0;
        _delay_ms(300);
        ICR1 = 0;
        OCR1C = 0;
        _delay_ms(100);
    }
    return 0;
}