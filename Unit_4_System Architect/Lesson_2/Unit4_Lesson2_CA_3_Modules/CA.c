/*
 * CA.c
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#include "CA.h"

//Variables
int CA_speed = 0 ;
int CA_distance = 0 ;
int CA_threshold = 50 ;

//STATE Pointer to Function
void (*CA_state) () ;

void US_Set_distance (int d)
{
	CA_distance = d ;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf ("US----------distance = %d------>CA \n",CA_distance) ;

}
STATE_define (CA_waiting)
{
	//State_Name
	CA_state_id = CA_waiting ;
	printf ("CA_Waiting_State: distance = %d   speed = %d \n",CA_distance,CA_speed) ;

	//State_Action
	CA_speed = 0 ;
	//DC_Motor(CA_speed)
	DC_Motor (CA_speed) ;

}

STATE_define (CA_driving)
{

	//State_Name
	CA_state_id = CA_driving ;
	printf ("CA_Waiting_State: distance = %d   speed = %d \n",CA_distance,CA_speed) ;

	//State_Action
	CA_speed = 30 ;
	//DC_Motor(CA_speed)
	DC_Motor (CA_speed) ;

}

