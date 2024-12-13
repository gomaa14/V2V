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


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/



/************Section :: Function Prototype  *********************/

/*
 * Description :
 * Functional responsible for Initialize the UART device by:
 * 1. Setup the Frame format like number of data bits, parity bit type and number of stop bits.
 * 2. Enable the UART.
 * 3. Setup the UART baud rate.
 */
void UART_init(uint32_t baud_rate);

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const uint8_t data);

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
uint8_t UART_recieveByte(void);

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const uint8_t *Str);

/*
 * Description :
 * Receive the required string until the '#' symbol through UART from the other UART device.
 */
void UART_receiveString(uint8_t *Str); // Receive until #

#endif /* UART_H_ */