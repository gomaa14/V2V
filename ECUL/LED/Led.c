/*
 * Led.c
 *
 * Created: 11/24/2024 4:51:46 PM
 *  Author: Gomaa Ayman
 */ 

#include "Led.h"


Std_ReturnType led_init(const led_t* led)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if (NULL == led)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		pin_config_t _pin = {.Direction = DIO_OUTPUT, .Port = led->port_name, .Pin = led->pin_name,
		.Logic = led->led_state};
		
		Ret = DIO_Init(&_pin);
		
	}
	
	return Ret;
}


Std_ReturnType led_Turn_on(const led_t* led)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if (NULL == led)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		pin_config_t _pin = {.Direction = DIO_OUTPUT, .Port = led->port_name, .Pin = led->pin_name,
		.Logic = led->led_state};
		
		Ret = DIO_Write(&_pin, DIO_HIGH);
		
		
	}
	
	return Ret;
}


Std_ReturnType led_Turn_off(const led_t* led)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if (NULL == led)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		pin_config_t _pin = {.Direction = DIO_OUTPUT, .Port = led->port_name, .Pin = led->pin_name,
		.Logic = led->led_state};
		
		Ret = DIO_Write(&_pin, DIO_LOW);
		
		
	}
	
	return Ret;
}


Std_ReturnType led_toggle(const led_t* led)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if (NULL == led)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		
		pin_config_t _pin = {.Direction = DIO_OUTPUT, .Port = led->port_name, .Pin = led->pin_name,
		.Logic = led->led_state};
		
		Ret = DIO_Toggle(&_pin);
		
		Ret = E_OK;
	}
	
	return Ret;
}
