#ifndef UART1_H_
#define UART1_H_

void UART1Init(void);
void UART1Rransmit(char data);
unsigned char UART1Receive(void);
void UART1PrintString(char *str);
void UART1Print1ByteNumber(unsigned char n);

#endif