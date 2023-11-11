/*
 * main.c
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */
 
#include "Platform_Types.h"
#include "Util.h"

#include "GPIO.h" 
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "Alarm_Monitor.h" 
#include "Main_Program.h"

void (*PS_State)() = STATE(PS_Init) ;
void (*Alarm_Act_State)() = STATE(Alarm_Act_Init) ;
void (*AM_State)() = STATE(AM_Alarm_OFF) ;
void (*MP_State)() = STATE(MP_High_Pressure) ;
 
int main (void)
{
	// Hardware Initialization
	GPIO_Init() ;
	
	// Infinite Loop
	while (1)
	{
		PS_State() ;
		Alarm_Act_State() ;
		AM_State() ;
		MP_State() ;
	}
	
	return 0 ;
}
  