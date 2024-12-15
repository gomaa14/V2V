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

ultrasonic_t ULtra1 = { .Trigger_Pin.Port = PORTA_INDEX,
	.Trigger_Pin.Pin = PIN_0,
	.Trigger_Pin.Direction = DIO_OUTPUT,
	.Trigger_Pin.Logic =DIO_LOW,
	
	.Echo_Pin.Port = PORTA_INDEX,
	.Echo_Pin.Pin = PIN_1,
	.Echo_Pin.Direction = DIO_INPUT
};

Std_ReturnType ret = E_NOT_OK;
uint16 dis;
uint16 dis_right = 0;
uint16 dis_left = 0;

int main(void)
{
	sei();
	Application_Init();
	
	
    while (1) 
    {
		ret &= Ultrasonic_Calculate_Distance(&ULtra1, &dis) ;
		_delay_ms(500);
		
		if(dis > STOP_DISTANCE)
		{

			Robot_Move_Forward();
			led_Turn_on(&led_1);
			UART_Transmit('F');
			
			
		}
		else if (dis < STOP_DISTANCE)
		{
			Robot_Stop();
			ret &= Servo_Set_Angle(0);
			_delay_ms(1000);
			ret &= Ultrasonic_Calculate_Distance(&ULtra1, &dis_right);
			_delay_ms(300);
			ret &= Servo_Set_Angle(180);
			_delay_ms(1000);
			ret &= Ultrasonic_Calculate_Distance(&ULtra1, &dis_left);
			_delay_ms(300);
			ret &= Servo_Set_Angle(90);
			if(dis_right>dis_left)
			{
				Robot_turn_Right90();
				led_Turn_off(&led_1);
				UART_Transmit('R');
				
				
			}
			else if(dis_right<dis_left)
			{
				Robot_turn_Left90();
				led_Turn_off(&led_1);
				UART_Transmit('L');
				
			}

		}
		
		
		
    }
}

void Application_Init(void)
{
	ret = led_init(&led_1);
	ret &= dc_motor_init(&motor_1);
	ret &= dc_motor_init(&motor_2);
	ret &= Servo_init();
	ret &= Ultrasonic_Init(&ULtra1);
	
	UART_Init(9600);
	
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

