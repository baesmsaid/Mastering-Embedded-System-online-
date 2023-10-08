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
int US_Get_distance_random (int l , int r , int count) ;

STATE_define (CA_waiting)
{
	//State_Name
	CA_state_id = CA_waiting ;

	//State_Action
	CA_speed = 0 ;
	//DC_Motor(CA_speed)

	//Event_Check
	//UltraSonic_Get_Distance(CA_distance)
	CA_distance = US_Get_distance_random (45 , 55 , 1) ;

	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf ("CA_Waiting_State: distance = %d   speed = %d \n",CA_distance,CA_speed) ;
}

STATE_define (CA_driving)
{

	//State_Name
	CA_state_id = CA_driving ;

	//State_Action
	CA_speed = 30 ;
	//DC_Motor(CA_speed)

	//Event_Check
	//UltraSonic_Get_Distance(CA_distance)
	CA_distance = US_Get_distance_random (45 , 55 , 1) ;

	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf ("CA_Waiting_State: distance = %d   speed = %d \n",CA_distance,CA_speed) ;

}

// l = Low Number , r = Range
int US_Get_distance_random (int l , int r , int count)
{
	//This will generate random number in range l and r
	int i ;
	for (i = 0 ; i < count ; i++)
	{
		int rand_num = (rand() % (r-l+1)) + l ;
		return rand_num ;
	}
}
