/*
 * Timer0.c
 *
 * Created: 11/24/2024 2:27:23 PM
 *  Author: Gomaa Ayman
 */ 


#include "Timer0.h"

static void (*_Timer0_OVF_ptr_) (void)=NULL;
static void (*_Timer0_OC_ptr_) (void)=NULL;

Std_ReturnType Timer0_Init(Timer0_t *obj)
{
	Std_ReturnType Ret = E_NOT_OK;
	if(NULL == obj)
	{
		Ret = E_NOT_OK;
	}
	else
	{
		switch (obj->Timer0_Mode)
		{
			case TIMER0_NORMAL_MODE:
			CLEAR_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
			case TIMER0_PHASECORRECT_MODE:
			SET_BIT(TCCR0,WGM00);
			CLEAR_BIT(TCCR0,WGM01);
			break;
			case TIMER0_CTC_MODE:
			CLEAR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
			case TIMER0_FASTPWM_MODE:
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			break;
		}
		/* PreScaler Configuration */
		TCCR0 &= 0XF8;		// 0b11111000
		TCCR0 |= (obj->Timer0_PreScaler);
		
		/* CallBack Configuration */
		_Timer0_OVF_ptr_ = obj->Timer0_OVF_Fptr;
		_Timer0_OC_ptr_  = obj->Timer0_OC_Fptr;
		
		/* OCO Mode Configuration */		
		switch (obj->OC0_Mode)
		{
			
			case OCO_DISCONNECTED:
			CLEAR_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break;
			case OCO_TOGGLE:
			SET_BIT(DDRB, 3);
			SET_BIT(TCCR0,COM00);
			CLEAR_BIT(TCCR0,COM01);
			break;
			case OCO_NON_INVERTING:
			SET_BIT(DDRB, 3);
			CLEAR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
			case OCO_INVERTING:
			SET_BIT(DDRB, 3);
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
			break;
		}
		
		Ret = E_OK;	
	}
	
	return Ret;
}

Std_ReturnType Timer0_OV_InterruptEnable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	SET_BIT(TIMSK,TOIE0);
	
	Ret = E_OK;
	return Ret;
	
}

Std_ReturnType Timer0_OV_InterruptDisable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	CLEAR_BIT(TIMSK,TOIE0);
	
	Ret = E_OK;
	return Ret;
}

Std_ReturnType Timer0_OC_InterruptEnable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	SET_BIT(TIMSK,OCIE0);
	
	Ret = E_OK;
	return Ret;
}

Std_ReturnType Timer0_OC_InterruptDisable(void)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	CLEAR_BIT(TIMSK,OCIE0);
	
	Ret = E_OK;
	return Ret;
	
	
}





ISR(TIMER0_OVF_vect)
{
	if(_Timer0_OVF_ptr_ !=NULL)
	{
		_Timer0_OVF_ptr_();
	}
}

ISR(TIMER0_COMP_vect)
{
	if(_Timer0_OC_ptr_ !=NULL)
	{
		_Timer0_OC_ptr_();
	}
}