/*
 * V2V.c
 *
 * Created: 11/24/2024 11:42:28 AM
 * Author : Gomaa Ayman 
 */ 

#define F_CPU 8000000 //8MHZ

#include "main.h"

led_t led_1 = { .port_name = PORTC_INDEX,
				.pin_name = PIN_0,
				.led_state = LED_ON
	
};

dc_motor_t motor_1 = {.dc_motor[0].dc_motor_port = PORTC_INDEX,
	.dc_motor[0].dc_motor_pin = PIN_1,
	.dc_motor[0].motor_status = DC_MOTOR_OFF,
	.dc_motor[1].dc_motor_port = PORTC_INDEX,
	.dc_motor[1].dc_motor_pin = PIN_2,
	.dc_motor[1].motor_status = DC_MOTOR_OFF
};

dc_motor_t motor_2 = {.dc_motor[0].dc_motor_port = PORTC_INDEX,
	.dc_motor[0].dc_motor_pin = PIN_3,
	.dc_motor[0].motor_status = DC_MOTOR_OFF,
	.dc_motor[1].dc_motor_port = PORTC_INDEX,
	.dc_motor[1].dc_motor_pin = PIN_4,
	.dc_motor[1].motor_status = DC_MOTOR_OFF
};


/*
Timer1_t obj1 = {.Timer1_OVF_Fptr = NULL,
				 .Timer1_OCA_Fptr = NULL,
				 .Timer1_OCB_Fptr = NULL,
				 .Timer1_ICU_Fptr = NULL,
				 .Timer1_Mode = TIMER1_NORMAL_MODE,
				 .Timer1_Prescaler = TIMER1_SCALER_8,
				 .OC1A_Mode = OCRA_DISCONNECTED,
				 .OC1B_Mode = OCRB_DISCONNECTED,
				 .ICU_Edge = RISING
};
*/


Std_ReturnType ret = E_NOT_OK;
int main(void)
{
	sei();
	Application_Init();
	
	
    while (1) 
    {
		
		
    }
}

void Application_Init(void)
{
	//ret = led_init(&led_1);
	ret &= dc_motor_init(&motor_1);
	ret &= dc_motor_init(&motor_2);
	ret = Servo_init();
}
void Robot_Move_Forward(void)
{
	ret= dc_motor_move_right(&motor_1);
	ret= dc_motor_move_right(&motor_2);
}

void Robot_Move_Backward(void)
{
	ret= dc_motor_move_left(&motor_1);
	ret= dc_motor_move_left(&motor_2);
}

void Robot_Move_Right(void)
{
	ret= dc_motor_move_right(&motor_1);
	ret = dc_motor_stop(&motor_2);
	
}

void Robot_Move_Left(void)
{
	ret= dc_motor_stop(&motor_1);
	ret = dc_motor_move_right(&motor_2);
}
void Robot_Stop(void)
{
	ret= dc_motor_stop(&motor_1);
	ret= dc_motor_stop(&motor_2);
	_delay_ms(600);
}
void Robot_turn_Right90(void)
{
	Robot_Move_Right();
	_delay_ms(1500);
	Robot_Stop();
}

void Robot_turn_Left90(void)
{
	Robot_Move_Left();
	_delay_ms(1500);
	Robot_Stop();
}

