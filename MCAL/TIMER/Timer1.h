/*
 * Timer1.h
 *
 * Created: 11/24/2024 5:41:13 PM
 *  Author: Gomaa Ayman
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_



/*******************Section :: Includes***********************************/
#include "../Registers.h"
#include "../../LIB/Bit_Math.h"
#include "../../LIB/Std_Types.h"



/************Section :: Macro Declaration *************************/


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/

//PreScaler
typedef enum{
	TIMER1_STOP=0,
	TIMER1_SCALER_1,
	TIMER1_SCALER_8,
	TIMER1_SCALER_64,
	TIMER1_SCALER_256,
	TIMER1_SCALER_1024,
	EXTERNAL0_FALLING,
	EXTERNAL0_RISING
}Timer1Scaler_type;


//Mode
typedef enum
{
	TIMER1_NORMAL_MODE=0,
	TIMER1_CTC_ICR_TOP_MODE,
	TIMER1_CTC_OCRA_TOP_MODE,
	TIMER1_FASTPWM_ICR_TOP_MODE,
	TIMER1_FASTPWM_OCRA_TOP_MODE

}Timer1Mode_type;

typedef enum
{
	OCRA_DISCONNECTED=0,
	OCRA_TOGGLE,
	OCRA_NON_INVERTING,
	OCRA_INVERTING

}OC1A_Mode_type;


typedef enum
{
	OCRB_DISCONNECTED=0,
	OCRB_TOGGLE,
	OCRB_NON_INVERTING,
	OCRB_INVERTING

}OC1B_Mode_type;


typedef enum{
	RISING,
	FALLING
}ICU_Edge_type;

typedef struct
{
	void (*Timer1_OVF_Fptr) (void);
	void (*Timer1_OCA_Fptr) (void);
	void (*Timer1_OCB_Fptr) (void);
	void (*Timer1_ICU_Fptr) (void);
	
	Timer1Mode_type  Timer1_Mode;
	Timer1Scaler_type Timer1_Prescaler;
	OC1A_Mode_type OC1A_Mode;
	OC1B_Mode_type OC1B_Mode;
	ICU_Edge_type ICU_Edge;
	
}Timer1_t;

/************Section :: Function Prototype  *********************/

Std_ReturnType Timer1_Init(const Timer1_t* obj);

Std_ReturnType Timer1_ICU_InterruptEnable(void);
Std_ReturnType Timer1_ICU_InterruptDisable(void);
Std_ReturnType Timer1_OVF_InterruptEnable(void);
Std_ReturnType Timer1_OVF_InterruptDisable(void);
Std_ReturnType Timer1_OCA_InterruptEnable(void);
Std_ReturnType Timer1_OCA_InterruptDisable(void);
Std_ReturnType Timer1_OCB_InterruptEnable(void);
Std_ReturnType Timer1_OCB_InterruptDisable(void);


Std_ReturnType Timer1_InputCaptureEdge(ICU_Edge_type edge);

#endif /* TIMER1_H_ */