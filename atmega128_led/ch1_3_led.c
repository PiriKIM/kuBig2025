#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRC = 0x0F;
    while(1)
    {
        unsigned char led_data = 0x00;

        while(1)
        {
            PORTC = led_data;
            led_data++;
            if(led_data > 0x0F)
                led_data = 0;
            _delay_ms(100);
        }
    }

    return 0;
}