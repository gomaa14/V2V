/*
 * Led.h
 *
 * Created: 11/24/2024 4:52:19 PM
 *  Author: Gomaa Ayman
 */ 


#ifndef LED_H_
#define LED_H_

/*******************Section :: Includes***********************************/
#include "../../MCAL/DIO/Dio.h"


/************Section :: Macro Declaration *************************/


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/

typedef enum
{
	LED_OFF = 0,
	LED_ON
}led_status_t;

typedef struct
{
	uint8_t port_name :2; // @ref port_index_t
	uint8_t pin_name  :3; // @ref pin_index_t
	uint8_t led_state :1; // @ref led_status_t
	
}led_t;

/************Section :: Function Prototype  *********************/

Std_ReturnType led_init(const led_t* led);
Std_ReturnType led_Turn_on(const led_t* led);
Std_ReturnType led_Turn_off(const led_t* led);
Std_ReturnType led_toggle(const led_t* led);



#endif /* LED_H_ */