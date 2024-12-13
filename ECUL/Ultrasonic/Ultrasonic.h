

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../MCAL/TIMER/timer0.h"


typedef struct{
	pin_config_t Trigger_Pin;
	pin_config_t Echo_Pin;
}ultrasonic_t;

Std_ReturnType Ultrasonic_Init(const ultrasonic_t *_config);
Std_ReturnType Ultrasonic_Calculate_Distance(const ultrasonic_t *_config, uint16 *Distance);






#endif /* ULTRASONIC_H_ */