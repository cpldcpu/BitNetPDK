#ifndef __SOFTUART_H
#define __SOFTUART_H

#include <stdint.h>

void PDK_autobaud(void);       // autobaud for the easypdkprogrammer. This needs to be called before sending anything on the UART
void PDK_sendchar(uint8_t);    // Send a single char on the serial port. So far, no receving is possible.
void PDK_sendhex8(uint8_t);    // Prints a hexadecimal representation of a 8 bit unsigned value on the UART.
void PDK_sendstring(char *);   // Sends a zero terminated string that can reside in RAM or ROM
void PDK_senduint16(uint16_t); // Prints a decimal representation of a 16 bit unsigned value on the UART.
void PDK_senduint32(uint32_t); // Prints a decimal representation of a 32 bit unsigned value on the UART.

// UART configuration 
#define TXPORT PA
#define TXPORTC PAC
#define TXPIN 7
#define BAUDRATE 115200

#define sl(x) _ ## x
#define s(y) sl(y)

#endif