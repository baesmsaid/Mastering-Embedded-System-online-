/*
 * US.c
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#include "US.h"

//Variables
int US_distance = 0 ;

//STATE Pointer to Function
void (*US_state) () ;
int US_Get_distance_random (int l , int r , int count) ;

void US_Init ()
{
	//Init Us Driver
	printf ("US_Init \n") ;
}
STATE_define (US_Busy)
{
	//State_Name
	US_state_id = US_Busy;

	//State_Action
	US_distance = US_Get_distance_random (45 , 55 , 1) ;

	printf ("US_Busy_State: distance = %d  \n",US_distance) ;
	US_Set_distance(US_distance) ;
	US_state = STATE (US_Busy) ;

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
