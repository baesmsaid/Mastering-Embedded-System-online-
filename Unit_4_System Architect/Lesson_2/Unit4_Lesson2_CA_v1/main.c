/*
 * main.c
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#include "CA.h"

void setup ()
{
	//Init all the drivers
	//Init IRQ......
	//Init HAL UltraSonic_Driver...DC_Driver
	//Set States Pointers for each Block
	CA_state = STATE(CA_waiting) ;

}

void main ()
{
	volatile int d ;
	setup () ;

	while (1)
	{
		//Call State for each Block
		CA_state ();
		//delay
		for (d =0 ; d<= 1000 ; d++) ;
	}
}
