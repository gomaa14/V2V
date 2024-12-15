/*
 * main.h
 *
 * Created: 11/24/2024 11:44:43 AM
 *  Author: Gomaa Ayman
 */ 


#ifndef MAIN_H_
#define MAIN_H_

/*******************Section :: Includes***********************************/
#include "ECUL/LED/Led.h"
#include "ECUL/DC_MOTOR/DC_Motor.h"
#include "ECUL/SERVO/Servo.h"
#include "ECUL/Ultrasonic/Ultrasonic.h"

#include "MCAL/UART/UART.h"




/************Section :: Macro Declaration *************************/

#define STOP_DISTANCE     40


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/



/************Section :: Function Prototype  *********************/
void Application_Init(void);
void Robot_Move_Forward(void);
void Robot_Move_Backward(void);
void Robot_Move_Right(void);
void Robot_Move_Left(void);
void Robot_Stop(void);
void Robot_turn_Right90(void);
void Robot_turn_Left90(void);



#endif /* MAIN_H_ */