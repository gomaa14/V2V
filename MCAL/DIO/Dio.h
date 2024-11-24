/*
 * Dio.h
 *
 * Created: 11/24/2024 12:20:05 PM
 *  Author: Gomaa Ayman
 */ 


#ifndef DIO_H_
#define DIO_H_

/*******************Section :: Includes***********************************/
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"
#include "../Registers.h"

/************Section :: Macro Declaration *************************/


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/


typedef enum
{
	DIO_LOW = 0,
	DIO_HIGH
}logic_t;

typedef enum
{
	DIO_INPUT = 0,
	DIO_OUTPUT
}direction_t;

typedef enum
{
	PIN_0=0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7

}pin_index_t;


typedef enum
{
	PORTA_INDEX = 0,
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX

}port_index_t;




typedef struct
{
	uint8_t Pin       :3;     /* @ref port_index_t */
	uint8_t Port      :2;     /* @ref pin_index_t  */
	uint8_t Logic     :1;     /* @ref logic_t      */
	uint8_t Direction :1;     /* @ref direction_t  */
	uint8_t Reserver  :1;	  /*  Reserver For New Feature */
}pin_config_t;




/************Section :: Function Prototype  *********************/
Std_ReturnType DIO_Init(const pin_config_t* _pin);
Std_ReturnType DIO_Write(const pin_config_t* _pin, logic_t value);
Std_ReturnType DIO_Toggle(const pin_config_t* _pin);
Std_ReturnType DIO_Read(const pin_config_t* _pin,  logic_t* value);




#endif /* DIO_H_ */