#include "ultrasonic.h"


static void Timer0_OVF_FUN(void);
volatile uint8_t Counter = 0;

volatile Timer0_t Timer0_Obj;

Std_ReturnType Ultrasonic_Init(const ultrasonic_t *_config)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if (NULL == _config)
	{
		 Ret = E_OK;
	}
	else
	{
		Ret = DIO_Init(&(_config->Trigger_Pin));
		Ret = DIO_Init(&(_config->Echo_Pin));
		// Initialize Timer0 to Operate on Normal MOde
		//Timer0_Init(TIMER0_NORMAL_MODE, TIMER0_SCALER_8, OCO_DISCONNECTED);
		
		Timer0_Obj.Timer0_Mode = TIMER0_NORMAL_MODE;
		Timer0_Obj.Timer0_PreScaler = TIMER0_SCALER_8;
		Timer0_Obj.OC0_Mode = OCO_DISCONNECTED;
		Timer0_Obj.Timer0_OVF_Fptr = Timer0_OVF_FUN;
		Ret = Timer0_Init(&Timer0_Obj);
		
	}
	
	
	return Ret;
}

Std_ReturnType Ultrasonic_Calculate_Distance(const ultrasonic_t *_config, uint16 *Distance)
{
	Std_ReturnType Ret = E_NOT_OK;
	
	if(NULL == _config || NULL == Distance)
	{
		Ret = E_NOT_OK;
	}
	
	else
	{
		uint16 Timer0_Value = 0;
		logic_t EchoPinLogic = DIO_LOW;
		
		Timer0_OV_InterruptEnable();
		//Timer0_OVF_SetCallBack(Timer0_OVF_FUN);
		/* Send Trigger Signal to the Ultrasonic Trigger Pin */
		DIO_Write(&(_config->Trigger_Pin), DIO_HIGH);
		_delay_us(10);
		DIO_Write(&(_config->Trigger_Pin), DIO_LOW);
		/* Wait the Echo pin to be High */
		while(DIO_LOW == EchoPinLogic){
			DIO_Read(&(_config->Echo_Pin), &EchoPinLogic);
		}
		
		/* Clear Timer0 Ticks -> Already Enabled */
		Counter = 0;
		TCNT0 = 0;
		/* Wait the Echo pin to be Low */
		while(DIO_HIGH == EchoPinLogic){
			DIO_Read(&(_config->Echo_Pin), &EchoPinLogic);
		}
		
		/* Read the time */
		//ret = Timer0_Read_Value(&timer0_timer_obj, &Timer0_Value);
		
		Timer0_Value = TCNT0;
		Timer0_Value += Counter*256;
		
		*Distance = ((uint16)(Timer0_Value / 58.8f)) + 1;
		Ret = E_OK;
	}
	
	return Ret;
}

static void Timer0_OVF_FUN(void)
{
	Counter++;
}

/*****************************************************************************/

