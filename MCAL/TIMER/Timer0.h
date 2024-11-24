/*
 * Timer0.h
 *
 * Created: 11/24/2024 2:26:59 PM
 *  Author: Gomaa Ayman
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_


/*******************Section :: Includes***********************************/
#include "../Registers.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"



/************Section :: Macro Declaration *************************/


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/

// PreScaler
typedef enum{
	TIMER0_STOP=0,
	TIMER0_SCALER_1,
	TIMER0_SCALER_8,
	TIMER0_SCALER_64,
	TIMER0_SCALER_256,
	TIMER0_SCALER_1024,
	EXTERNALl_FALLING,
	EXTERNAL_RISING
}Timer0Scaler_type;

//Mode
typedef enum
{
	TIMER0_NORMAL_MODE=0,
	TIMER0_PHASECORRECT_MODE,
	TIMER0_CTC_MODE,
	TIMER0_FASTPWM_MODE

}Timer0Mode_type;

//Output Compare Match
typedef enum
{
	OCO_DISCONNECTED=0,
	OCO_TOGGLE,
	OCO_NON_INVERTING,
	OCO_INVERTING

}OC0Mode_type;


typedef struct  
{
	void (*Timer0_OVF_Fptr) (void);
	void (*Timer0_OC_Fptr) (void);
	Timer0Mode_type Timer0_Mode;
	Timer0Scaler_type Timer0_PreScaler;
	OC0Mode_type OC0_Mode;
}Timer0_t;


/************Section :: Function Prototype  *********************/

Std_ReturnType Timer0_Init(Timer0_t *obj);
Std_ReturnType Timer0_OV_InterruptEnable(void);
Std_ReturnType Timer0_OV_InterruptDisable(void);
Std_ReturnType Timer0_OC_InterruptEnable(void);
Std_ReturnType Timer0_OC_InterruptDisable(void);



#endif /* TIMER0_H_ */