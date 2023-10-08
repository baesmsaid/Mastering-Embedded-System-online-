/*
 * DC_Motor.c
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#include "DC_Motor.h"

//Variables
int DC_speed = 0 ;

//STATE Pointer to Function
void (*DC_state) () ;

void DC_Motor_Init ()
{
	//Init PWM
	printf ("DC Init \n") ;
}

void DC_Motor (int s)
{
	DC_speed = s ;
	DC_state = STATE(DC_Busy) ;
	printf ("CA----------speed = %d------>DC \n",DC_speed) ;
}

STATE_define (DC_Idle)
{
	//State_Name
	DC_state_id = DC_Idle;

	//State_Action
	//Call PWM to make speed = DC_speed

	printf ("DC_Idle_State:  speed = %d \n",DC_speed) ;
}

STATE_define (DC_Busy)
{

	//State_Name
	DC_state_id = DC_Busy ;

	//State_Action
	//Call PWM to make speed = DC_speed

	DC_state = STATE(DC_Idle) ;

	printf ("DC_Busy_State:  speed = %d \n",DC_speed) ;

}

