// uart를 이용해서 시리얼 통신으로 센서 값을 0.1ch 간격으로 출력
// -->> CDS ADC_data : xxxx

#include "lcd.h"
#include "uart0.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <util/delay.h>

volatile uint16_t adcResult = 0;

int main()
{
    uart0Init();
    lcdInit();

    stdin = &INPUT;
    stdout = &OUTPUT;

    ADMUX = 0x40;   // ADC0 사용. single mode, 0번 채널, 3.3V 외부 기준 전압(AREF)
    ADCSRA = 0xAF;  // 10101111 ADC 허가, free running mode, Interrupt
    ADCSRA |= 0x40; // ADC 개시
    sei();          // 전역 인터럽트 허용
    printf("\r\nHi, I'm Atmega128\r\n");

    lcdGotoXY(0, 0);
    lcdPrintData("Light Sensor", 12);
    char buf[16];

    while (1)
    {
        lcdGotoXY(0, 1);
        sprintf(buf, "L: %u", adcResult);
        lcdPrintData(buf, strlen(buf));
        printf("CDS ADC_data : %u\r\n", adcResult);
        _delay_ms(100);
    }
    return 0;
}

ISR(ADC_vect)
{
    cli();
    adcResult = ADC; // 2^16 -> 0 ~ 1023
    sei();
}