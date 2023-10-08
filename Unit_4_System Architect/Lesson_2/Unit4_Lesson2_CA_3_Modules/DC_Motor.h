/*
 * DC_Motor.h
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "state.h"

//Define States
enum
{
	DC_Idle,
	DC_Busy
}DC_state_id;

//Declare States Functions CA
STATE_define(DC_Idle) ;
STATE_define(DC_Busy) ;

void DC_Motor_Init () ;

//STATE Pointer to Function
extern void (*DC_state) () ;

#endif /* DC_MOTOR_H_ */
