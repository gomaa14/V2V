/*
 * DC_Motor.h
 *
 * Created: 11/24/2024 5:09:42 PM
 *  Author: Gomaa Ayman
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************Section :: Includes***********************************/
#include "../../MCAL/DIO/Dio.h"


/************Section :: Macro Declaration *************************/
#define DC_MOTOR_OFF 0X00
#define DC_MOTOR_ON  0X01

#define MOTOR_MOVE_RIGHT 0X02
#define MOTOR_MOVE_LEFT  0X03


#define DC_MOTOR_PIN_1 0
#define DC_MOTOR_PIN_2 1


/************Section :: Macro Function Declaration ****************/


/************Section :: User Define Data Type *********************/
typedef struct
{
	uint8_t dc_motor_port :2;
	uint8_t dc_motor_pin  :3;
	uint8_t motor_status  :1;
	
}dc_motor_pin_t;

typedef struct
{
	dc_motor_pin_t dc_motor[2];
	
}dc_motor_t;

/************Section :: Function Prototype  *********************/
Std_ReturnType dc_motor_init(const dc_motor_t* obj);
Std_ReturnType dc_motor_move_right(const dc_motor_t* obj);
Std_ReturnType dc_motor_move_left(const dc_motor_t* obj);
Std_ReturnType dc_motor_stop(const dc_motor_t* obj);


#endif /* DC_MOTOR_H_ */