// PWM 설정 fast PWM, timer3, COM3A1
// FND 설정
// 버저를 이용한 프로그램
// 버튼 인터럽트 활성화 PE4, 5, 6, 7
// 버튼엔 맞는 소리를 2초 동안 출력, 2초 후에는 무음
// FND에 버튼이 눌린 번호를 출력
#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

uint16_t doReMi[16] = {523, 587, 659, 698, 783, 880, 987, 1046, 523, 587, 659, 698, 783, 880, 987, 1046};
// uint8_t piano = 0;
uint8_t numbers[16] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F, 0xF7, 0xFC, 0xB9, 0xBF, 0xF9, 0xF1};

int main(void)
{
    // PB7 핀 피에조 -> OCR1C
    DDRB = _BV(PB7);    // 7번 출력 설정
    DDRA = 0xFF;        // FND 출력 설정
    DDRE = 0x00;        // 버튼 입력 설정

    TCCR1A = _BV(COM1C1) | _BV(WGM11);  //COM 10 설정 -> clear on compare
    TCCR1B = _BV(WGM13) | _BV(WGM12) | _BV(CS00);  // 분주비 1 -> No Prescale, fast PWM
    // TCCR1C = 0x00;

    sei();  // 전역 인터럽트 허용

    uint8_t switch_flag = 0;

    while (1)
    {
        switch_flag = 0;

        // 스위치가 눌릴 때 까지 대기
        while(PINE >> 4 == 0x00)
        {
            PORTA = numbers[switch_flag];
            ICR1 = 0;
            OCR1C = 0;
        }

        switch_flag = PINE >> 4;
        
        PORTA = numbers[switch_flag];
        ICR1 = 14745600 / doReMi[switch_flag];    // 주파수만큼 duty cycle을 설정 하겠다.
        OCR1C = ICR1 / 4;   // 절반을 on 시키겠다.
        _delay_ms(2000);
    }
    return 0;
}