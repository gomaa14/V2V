/*
 * Std_Types.h
 *
 * Created: 11/24/2024 11:52:12 AM
 *  Author: Gomaa Ayman
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


/*..........section:includes.........*/
//#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>


/*.............section:data type declaration.......... */
typedef unsigned char  uint8_t;
typedef unsigned short uint16;
typedef unsigned long  uint32_t;

typedef signed char  sint8_t;
typedef signed short sint16_t;
typedef signed long  sint32_t;


typedef float float32_t;
typedef double float64_t;


typedef uint8_t     Std_ReturnType;




/*..........section:macro declaration ............*/
#define ZERO_INIT        0

#define E_OK       1
#define E_NOT_OK   0




#endif /* STD_TYPES_H_ */