/*

 * UART.c
 *
 * Created: 12/13/2024 11:22:54 PM
 *  Author: Hossam Reda
 */ 

#include "UART.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/Bit_Math.h"
#include "avr/io.h" /* To use the UART Registers */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void UART_Init(uint32_t baud_rate) 
{
	uint16_t ubrr_value = BAUD_PRESCALE(baud_rate);
	UBRRH = (uint8_t)(ubrr_value >> 8); // Set the upper byte of the baud rate
	UBRRL = (uint8_t)ubrr_value;       // Set the lower byte of the baud rate
	
	UCSRB = (1 << RXEN) | (1 << TXEN); // Enable receiver and transmitter
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // 8-bit data, 1 stop bit, no parity
}

void UART_Transmit(uint8_t data)
{
	while (!(UCSRA & (1 << UDRE))); // Wait until the transmit buffer is empty
	UDR = data; // Send the data
}

uint8_t UART_Receive(void)
{
	while (!(UCSRA & (1 << RXC))); // Wait until data is received
	return UDR; // Return the received data
}

void UART_TransmitString(const char *str)
{
	while (*str) 
	{
		UART_Transmit(*str++); // Transmit each character in the string
	}
}