#include <stdio.h>
#include <wiringPi.h>

// GPIO PIN
#define LED1 23
#define LED2 24
#define LED3 25
#define LED4 1

int main(void)
{
    wiringPiSetupGpio();    // BCM 기준 GPIO 핀번호
    pinMode(LED1, OUTPUT);  // PIN 입출력 설정
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    while(1)
    {
        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        digitalWrite(LED3, HIGH);
        digitalWrite(LED4, HIGH);
    }

    printf("안녕하세요!");
    return 0;
}