#include <avr/io.h>
#include <util/delay.h>

int main()
{
    DDRC = 0x0F;
    unsigned char led_data;
    led_data = 0x01;
    int direction = 1;
    while (1)
    {
        while (1)
        {
            PORTC = led_data;
            if (led_data > 0x04)
                direction = 0;
            if (led_data == 1)
            {
                direction = 1;
                led_data = 1;
            }

            if (direction)
                led_data <<= 1;
            else
                led_data >>= 1;
            _delay_ms(100);
        }
    }
/*
    DDRC = 0x0F;
    unsigned char led_data;
    led_data = 0x01;
    int direction = 0;
    while(1)
    {
        if(led_data == 0x08 && direction == 0)
            direction = 1;
        if(led_data == 0x01 && direction == 1)
        {
            direction = 0;
            led_data = 1;
        }

        PORTC = led_data;
        _delay_ms(100);
        if (direction)
            led_data >>= 1;
        else
            led_data <<= 1;
    }
*/
/*
    DDRC = 0x0F;
    unsigned char led_data = 0x00;
    PORTC = led_data;
    while(1)
    {
        for(int i = 3; i >= 0; i--)
        {
            led_data = 1 << i;
            PORTC = led_data;
            _delay_ms(100);
        }
        for(int i = 0; i < 4; i++)
        {
            led_data = 1 << i;
            PORTC = led_data;
            _delay_ms(100);
        }
    }
*/
    return 0;
}