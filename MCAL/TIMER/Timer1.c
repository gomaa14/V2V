/*
 * Timer1.c
 *
 * Created: 11/24/2024 5:41:35 PM
 *  Author: Gomaa Ayman
 */ 


#include "Timer1.h"

static void (*_Timer1_OVF_ptr_) (void)=NULL;
static void (*_Timer1_OCA_ptr_) (void)=NULL;
static void (*_Timer1_OCB_ptr_) (void)=NULL;
static void (*_Timer1_ICU_ptr_) (void)=NULL;


Std_ReturnType Timer1_Init(const Timer1_t* obj)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if(obj == NULL)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		switch (obj->Timer1_Mode)
		{
			case TIMER1_NORMAL_MODE:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			CLEAR_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
			case TIMER1_CTC_ICR_TOP_MODE:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			case TIMER1_CTC_OCRA_TOP_MODE:
			CLEAR_BIT(TCCR1A,WGM10);
			CLEAR_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			CLEAR_BIT(TCCR1B,WGM13);
			break;
			case TIMER1_FASTPWM_ICR_TOP_MODE:
			CLEAR_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
			case TIMER1_FASTPWM_OCRA_TOP_MODE:
			SET_BIT(TCCR1A,WGM10);
			SET_BIT(TCCR1A,WGM11);
			SET_BIT(TCCR1B,WGM12);
			SET_BIT(TCCR1B,WGM13);
			break;
		}
		
		switch (obj->OC1A_Mode)
		{
			case OCRA_DISCONNECTED:
			CLEAR_BIT(TCCR1A,COM1A0);
			CLEAR_BIT(TCCR1A,COM1A1);
			break;
			case OCRA_TOGGLE:
			SET_BIT(DDRD, 5);
			SET_BIT(TCCR1A,COM1A0);
			CLEAR_BIT(TCCR1A,COM1A1);
			break;
			case OCRA_NON_INVERTING:
			SET_BIT(DDRD, 5);
			CLEAR_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
			case OCRA_INVERTING:
			SET_BIT(DDRD, 5);
			SET_BIT(TCCR1A,COM1A0);
			SET_BIT(TCCR1A,COM1A1);
			break;
		}
		
		switch (obj->OC1B_Mode)
		{
			case OCRB_DISCONNECTED:
			CLEAR_BIT(TCCR1A,COM1B0);
			CLEAR_BIT(TCCR1A,COM1B1);
			break;
			case OCRB_TOGGLE:
			SET_BIT(DDRD, 4);
			SET_BIT(TCCR1A,COM1B0);
			CLEAR_BIT(TCCR1A,COM1B1);
			break;
			case OCRB_NON_INVERTING:
			SET_BIT(DDRD, 4);
			CLEAR_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
			case OCRB_INVERTING:
			SET_BIT(DDRD, 4);
			SET_BIT(TCCR1A,COM1B0);
			SET_BIT(TCCR1A,COM1B1);
			break;
		}
		
		TCCR1B &= 0XF8;
		TCCR1B |= (obj->Timer1_Prescaler);
		
		if(obj->ICU_Edge == RISING)
		{
			SET_BIT(TCCR1B,ICES1);
			CLEAR_BIT(DDRD, 6);       // Configure PD6 to be INPUT 
		}
		else if(obj->ICU_Edge == FALLING)
		{
			CLEAR_BIT(TCCR1B,ICES1);
			CLEAR_BIT(DDRD, 6);       // Configure PD6 to be INPUT 
		}
		
		_Timer1_OVF_ptr_ = obj->Timer1_OVF_Fptr;
		_Timer1_OCA_ptr_ = obj->Timer1_OCA_Fptr;
		_Timer1_OCB_ptr_ = obj->Timer1_OCB_Fptr;
		_Timer1_ICU_ptr_ = obj->Timer1_ICU_Fptr;
		
		Ret = E_OK;
	}
	
	return Ret;
	
}

Std_ReturnType Timer1_ICU_InterruptEnable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	SET_BIT(TIMSK,TICIE1);
	Ret = E_OK;
	return Ret;
	
}
Std_ReturnType Timer1_ICU_InterruptDisable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	CLEAR_BIT(TIMSK,TICIE1);
	Ret = E_OK;
	return Ret;
}
Std_ReturnType Timer1_OVF_InterruptEnable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	SET_BIT(TIMSK,TOIE1);
	Ret = E_OK;
	return Ret;
}
Std_ReturnType Timer1_OVF_InterruptDisable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	CLEAR_BIT(TIMSK,TOIE1);
	Ret = E_OK;
	return Ret;
}
Std_ReturnType Timer1_OCA_InterruptEnable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	SET_BIT(TIMSK,OCIE1A);
	Ret = E_OK;
	return Ret;
}
Std_ReturnType Timer1_OCA_InterruptDisable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	CLEAR_BIT(TIMSK,OCIE1A);
	Ret = E_OK;
	return Ret;
}
Std_ReturnType Timer1_OCB_InterruptEnable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	SET_BIT(TIMSK,OCIE1B);
	Ret = E_OK;
	return Ret;
}
Std_ReturnType Timer1_OCB_InterruptDisable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	CLEAR_BIT(TIMSK,OCIE1B);
	Ret = E_OK;
	return Ret;
}

ISR(TIMER1_OVF_vect)
{
	if(_Timer1_OVF_ptr_!=NULL)
	{
		_Timer1_OVF_ptr_();
	}
}
ISR(TIMER1_COMPA_vect)
{
	if(_Timer1_OCA_ptr_!=NULL)
	{
		_Timer1_OCA_ptr_();
	}
}
ISR(TIMER1_COMPB_vect)
{
	if(_Timer1_OCB_ptr_!=NULL)
	{
		_Timer1_OCB_ptr_();
	}
}
ISR(TIMER1_CAPT_vect)
{
	if(_Timer1_ICU_ptr_!=NULL)
	{
		_Timer1_ICU_ptr_();
	}
}









