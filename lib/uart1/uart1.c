#include <avr/io.h>

void UART1Init(void)
{
    UCSR0A |= _BV(U2X1);    // 2배속 모드
    UCSR0B = 0x18;  // 0b00011000 >> RX enable, TX enable
    UCSR0C = 0x06;  // 0b00000110 >> 비동기, no Parity, 1 stop bit

    UBRR0H = 0x00;
    UBRR0L = 0x07;  // 115200 bps --> 9600 bps
}
void UART1Rransmit(char data)
{
    // 내일
}
unsigned char UART1Receive(void)
{
    while((UCSR0A & 0x80) == 0)
        ;
    return UDR0;
}
void UART1PrintString(char *str);
void UART1Print1ByteNumber(unsigned char n);