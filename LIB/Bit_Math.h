/*
 * Bit_Math.h
 *
 * Created: 11/24/2024 11:54:22 AM
 *  Author: Gomaa Ayman
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


#define BIT_MASK     (uint8_t)     1

/*..........section:macro Function declaration ............*/

//Set Bit in register
#define SET_BIT(REG, BIT_BOSN)          (REG |= ( BIT_MASK << BIT_BOSN))

//clear Bit in register
#define CLEAR_BIT(REG, BIT_BOSN)        (REG &= ~( BIT_MASK << BIT_BOSN))

//toggle Bit in register
#define TOGGLE_BIT(REG, BIT_BOSN)       (REG ^= ( BIT_MASK << BIT_BOSN))

//Read Bit in register
#define READ_BIT(REG, BIT_BOSN)         ((REG >>BIT_BOSN) & BIT_MASK)

#define SET_REG(Reg)					(Reg = 0xFF)
#define CLEAR_REG(Reg)					(Reg = 0x00)
#define TOOGLE_REG(Reg)					(Reg ^= 0xFF)
#define ASSIGN_REG(Reg,Value)			(Reg = Value)
#define SET_BITS_REG(Reg,Mask)			(Reg |= (Mask))
#define CLEAR_BITS_REG(Reg,Mask)		(Reg = (Reg&(~Mask)))






#endif /* BIT_MATH_H_ */