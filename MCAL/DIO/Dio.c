/*
 * Dio.c
 *
 * Created: 11/24/2024 12:19:43 PM
 *  Author: Gomaa Ayman
 */ 


#include "Dio.h"

/*Reference to Data Direction Register */
volatile uint8_t* ddr_register [] = {&DDRA, &DDRB, &DDRC, &DDRD};

/*Reference to Port write Register */
volatile uint8_t* port_register [] = {&PORTA, &PORTB, &PORTC, &PORTD};

/*Reference to pin Status Register  */
volatile uint8_t* pin_register  [] = {&PINA, &PINB, &PINC, &PIND};



Std_ReturnType DIO_Init(const pin_config_t* _pin)
{
	Std_ReturnType Ret = E_NOT_OK;
	if (NULL == _pin)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		switch(_pin->Direction)
		{
			case DIO_INPUT :
			CLEAR_BIT(*ddr_register[_pin->Port], _pin->Pin);
			break;
			case DIO_OUTPUT :
			SET_BIT(*ddr_register[_pin->Port], _pin->Pin);
			break;
		}
		if (_pin->Direction == DIO_OUTPUT)
		{
			if (_pin->Logic == DIO_LOW)
			{
				CLEAR_BIT(*port_register[_pin->Port], _pin->Pin);
			}
			else if (_pin->Logic == DIO_HIGH)
			{
				SET_BIT(*port_register[_pin->Port], _pin->Pin);
			}
		}
		else{/* Nothing */}
		
		Ret = E_OK;	
	}
	
	return Ret;
}

Std_ReturnType DIO_Write(const pin_config_t* _pin, logic_t value)
{
	Std_ReturnType Ret = E_NOT_OK;
	if (NULL == _pin)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		if (value == DIO_HIGH)
		{
			SET_BIT(*port_register[_pin->Port], _pin->Pin);
		}
		else if (value == DIO_LOW)
		{
			CLEAR_BIT(*port_register[_pin->Port], _pin->Pin);
		}
		else{/* Nothing */}
		
		Ret = E_OK;
	}
	return Ret;
	
}

Std_ReturnType DIO_Toggle(const pin_config_t* _pin)
{
	Std_ReturnType Ret = E_NOT_OK;
	if (NULL == _pin)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		TOGGLE_BIT(*port_register[_pin->Port], _pin->Pin);
		
		Ret = E_OK;
	}
	return Ret;
	
}

Std_ReturnType DIO_Read(const pin_config_t* _pin,  logic_t* value)
{
	Std_ReturnType Ret = E_NOT_OK;
	if ( (NULL == _pin) || (NULL == value))
	{
		Ret = E_NOT_OK;
	}
	else
	{
		*value = READ_BIT(*pin_register[_pin->Port], _pin->Pin);
		
		Ret = E_OK;
	}
	return Ret;
}
