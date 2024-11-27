/* 
 * File:   ICU.h
 * Author: Hossam Reda
 *
 * Created on November 9, 2024, 2:25 PM
 */

#ifndef ICU_H
#define	ICU_H

/*Section : Includes */
#include "../../mcal_std_types.h"
/*Section : Macro Declaration*/

/*Section : Macro Function*/

/*Section : Data type Declaration*/

typedef enum {
	NO_CLOCK, F_CPU_CLOCK, F_CPU_8, F_CPU_64, F_CPU_256, F_CPU_1024
} ICU_ClockType;

typedef enum {
	FALLING=0,
    RAISING 
} ICU_EdgeType;

typedef struct {
	ICU_ClockType clock;
	ICU_EdgeType edge;
} ICU_ConfigType;

/*Section : Function Declaration*/

/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType *Config_Ptr);

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_setCallBack(void (*a_ptr)(void));

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_EdgeType edgeType);

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_deInit(void);


#endif	/* ICU_H */

