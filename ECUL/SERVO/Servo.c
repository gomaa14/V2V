/*
 * Servo.c
 *
 * Created: 11/24/2024 4:12:54 PM
 *  Author: Gomaa Ayman
 */ 

#include "Servo.h"



Std_ReturnType Servo_init(void)
{
	Std_ReturnType Ret = E_NOT_OK; 
	/*set timer 1 preScaler to 8to get 1us tick time
	use fast mode with top value at OCRA reg to set the freq of servo
	diSconnect OC1A PIN ,and generate the PWM on OC1B PIN with non inverting mode to use OCR1B reg as the ton value*/
	
	Timer1_t obj1 = {.Timer1_OVF_Fptr = NULL,
		.Timer1_OCA_Fptr = NULL,
		.Timer1_OCB_Fptr = NULL,
		.Timer1_ICU_Fptr = NULL,
		.Timer1_Mode = TIMER1_FASTPWM_OCRA_TOP_MODE,
		.Timer1_Prescaler = TIMER1_SCALER_8,
		.OC1A_Mode = OCRA_DISCONNECTED,
		.OC1B_Mode = OCRB_NON_INVERTING,
		.ICU_Edge = RISING
	};
	Ret = Timer1_Init(&obj1);
	OCR1A=19999;//20000us to get 50hz
	OCR1B=999;// 1000us ton to get angle zero
	
	
	return Ret;
}

Std_ReturnType Servo_Set_Angle(uint8_t Angle)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	OCR1B=(((uint32_t)Angle*1000)/180)+999;
	
	Ret =  E_OK;
	return Ret;
}