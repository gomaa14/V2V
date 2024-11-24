/*
 * DC_Motro.c
 *
 * Created: 11/24/2024 5:09:18 PM
 *  Author: Gomaa Ayman
 */ 

#include "DC_Motor.h"


Std_ReturnType dc_motor_init(const dc_motor_t* obj)
{
	Std_ReturnType Ret =E_NOT_OK;
	if(NULL == obj)
	{
		Ret =E_NOT_OK;
	}
	else
	{
		pin_config_t pin_1;
		pin_1.Pin = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_pin;
		pin_1.Port = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_port;
		pin_1.Direction = DIO_OUTPUT;
		pin_1.Logic = obj->dc_motor[DC_MOTOR_PIN_1].motor_status;
		
		Ret = DIO_Init(&pin_1);
		
		pin_config_t pin_2;
		pin_2.Pin = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_pin;
		pin_2.Port = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_port;
		pin_2.Direction = DIO_OUTPUT;
		pin_2.Logic = obj->dc_motor[DC_MOTOR_PIN_2].motor_status;
		
		Ret &= DIO_Init(&pin_2);
		
	}
	
	return Ret;
}
Std_ReturnType dc_motor_move_right(const dc_motor_t* obj)
{
	Std_ReturnType Ret =E_NOT_OK;
	if(NULL == obj)
	{
		Ret =E_NOT_OK;
	}
	else
	{
		pin_config_t pin_1;
		pin_1.Pin = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_pin;
		pin_1.Port = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_port;
		pin_1.Direction = DIO_OUTPUT;
		pin_1.Logic = obj->dc_motor[DC_MOTOR_PIN_1].motor_status;
		
		pin_config_t pin_2;
		pin_2.Pin = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_pin;
		pin_2.Port = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_port;
		pin_2.Direction = DIO_OUTPUT;
		pin_2.Logic = obj->dc_motor[DC_MOTOR_PIN_2].motor_status;
		
		Ret = DIO_Write(&pin_1, DIO_HIGH);
		Ret&= DIO_Write(&pin_2, DIO_LOW);
		
		
		Ret = E_OK;
	}
	
	return Ret;
}
Std_ReturnType dc_motor_move_left(const dc_motor_t* obj)
{
	Std_ReturnType Ret =E_NOT_OK;
	if(NULL == obj)
	{
		Ret =E_NOT_OK;
	}
	else
	{
		pin_config_t pin_1;
		pin_1.Pin = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_pin;
		pin_1.Port = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_port;
		pin_1.Direction = DIO_OUTPUT;
		pin_1.Logic = obj->dc_motor[DC_MOTOR_PIN_1].motor_status;
		
		pin_config_t pin_2;
		pin_2.Pin = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_pin;
		pin_2.Port = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_port;
		pin_2.Direction = DIO_OUTPUT;
		pin_2.Logic = obj->dc_motor[DC_MOTOR_PIN_2].motor_status;
		
		Ret = DIO_Write(&pin_1, DIO_LOW);
		Ret &= DIO_Write(&pin_2, DIO_HIGH);
		
		
		Ret = E_OK;
	}
	
	return Ret;
}
Std_ReturnType dc_motor_stop(const dc_motor_t* obj)
{
	Std_ReturnType Ret =E_NOT_OK;
	if(NULL == obj)
	{
		Ret =E_NOT_OK;
	}
	else
	{
		pin_config_t pin_1;
		pin_1.Pin = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_pin;
		pin_1.Port = obj->dc_motor[DC_MOTOR_PIN_1].dc_motor_port;
		pin_1.Direction = DIO_OUTPUT;
		pin_1.Logic = obj->dc_motor[DC_MOTOR_PIN_1].motor_status;
		
		pin_config_t pin_2;
		pin_2.Pin = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_pin;
		pin_2.Port = obj->dc_motor[DC_MOTOR_PIN_2].dc_motor_port;
		pin_2.Direction = DIO_OUTPUT;
		pin_2.Logic = obj->dc_motor[DC_MOTOR_PIN_2].motor_status;
		
		Ret  = DIO_Write(&pin_1, DIO_LOW);
		Ret &= DIO_Write(&pin_2, DIO_LOW);
		
		
		Ret = E_OK;
	}
	
	return Ret;
}