#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    uint8_t numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x6F};
    //int count = 0;
    DDRA = 0xFF;    // 출력모드로 한다.
    srand(time(NULL));
    while(1)
    {
        PORTA = numbers[rand() % 10];
        //count = (count + 1) % 10;

        _delay_ms(500);
    }

    return 0;
}