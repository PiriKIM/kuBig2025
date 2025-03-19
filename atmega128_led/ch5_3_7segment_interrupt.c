// 인터럽트로 FND를 점멸.
// INT5 을 누르면 phase 1 -> phase 2 or phase2 -> phase 1
// phase 1 : FND가 빠르게 상승하는 코드. 100ms 간격.
// phase 2 : FND를 순간 멈추게 함.
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t timeStop = 0; // 인터럽트에 쓸 변수, volatile 필수

int main()
{
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
    int count = 0;

    DDRA = 0xFF; // FND(7segment) 출력

    EIMSK = 0x20;                    // 0b00100000   INT5
    EICRB = _BV(ISC51) | _BV(ISC50); // 인터럽트 5은 상승
    sei();

    while (1)
    {
        if (timeStop == 0)
        {
            PORTA = numbers[count];
            count = (count + 1) % 10;
        }
        _delay_ms(500);
    }

    return 0;
}

ISR(INT5_vect)
{
    cli(); // sei() 반대 설정 SREG -> I unset -> 0
    timeStop ^= 1;
    // if (timeStop == 0)
    //     timeStop = 1;
    // else
    //     timeStop = 0;
    sei();
}