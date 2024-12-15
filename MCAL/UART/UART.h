/*
 * UART.h
 *
 * Created: 12/13/2024 11:22:43 PM
 *  Author: Hossam Reda
 */ 


#ifndef UART_H_
#define UART_H_

/*******************Section :: Includes***********************************/

#include "../../LIB/Std_Types.h"

/************Section :: Macro Declaration *************************/

#define F_CPU 8000000UL // Define the system clock frequency

/************Section :: Macro Function Declaration ****************/

#define BAUD_PRESCALE(baud_rate) ((F_CPU / (16UL * baud_rate)) - 1)

/************Section :: User Define Data Type *********************/



/************Section :: Function Prototype  *********************/

void UART_Init(uint32_t baud_rate);
void UART_Transmit(uint8_t data);
uint8_t UART_Receive(void);
void UART_TransmitString(const char *str);

#endif /* UART_H_ */