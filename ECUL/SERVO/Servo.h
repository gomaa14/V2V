/*
 * Servo.h
 *
 * Created: 11/24/2024 4:13:10 PM
 *  Author: Gomaa Ayman
 */ 


#ifndef SERVO_H_
#define SERVO_H_


/*******************Section :: Includes***********************************/
#include "../../MCAL/TIMER/Timer1.h"




/************Section :: Macro Declaration *************************/


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/


/************Section :: Function Prototype  *********************/


Std_ReturnType Servo_init(void);

Std_ReturnType Servo_Set_Angle(uint8_t Angle);


#endif /* SERVO_H_ */