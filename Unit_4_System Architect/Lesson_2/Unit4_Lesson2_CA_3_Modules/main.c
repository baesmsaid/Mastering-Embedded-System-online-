/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#include "CA.h"
#include "US.h"
#include "DC_Motor.h"

void setup ()
{
	//Init all the drivers
	//Init IRQ......
	//Init HAL UltraSonic_Driver...DC_Driver
	//Init Block
	US_Init() ;
	DC_Motor_Init() ;
	//Set States Pointers for each Block
	CA_state = STATE (CA_waiting) ;
	US_state = STATE (US_Busy) ;
	DC_state = STATE (DC_Idle) ;
}

void main ()
{
	volatile int d ;
	setup () ;

	while (1)
	{
		//Call State for each Block
		US_state () ;
		CA_state () ;
		DC_state () ;
		//delay
		for (d =0 ; d<= 1000 ; d++) ;
	}
}
