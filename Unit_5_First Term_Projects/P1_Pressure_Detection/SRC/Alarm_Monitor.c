/*
 * Alarm_Monitor.c
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */
 
#include "Alarm_Monitor.h"

// Define Status
enum {
	AM_Alarm_OFF,
	AM_Alarm_ON,
	AM_Waiting
}E_AM_Status ;
 
STATE_Define(AM_Alarm_OFF)
{
	// State Action
	E_AM_Status = AM_Alarm_OFF ;
	
	// Stop Alarm Actuator
	AA_Stop_Alarm();
	
	// Check Event and Update State
	if (MP_High_Pressure_Detection() == TRUE)
	{
		AM_State = STATE(AM_Alarm_ON) ;
	}
}

STATE_Define(AM_Alarm_ON)
{
	// State Action
	E_AM_Status = AM_Alarm_ON ;
	
	// Start Alarm Actuator
	AA_Start_Alarm() ;
	
	// Check Event and Update State
		AM_State = STATE(AM_Waiting);
}
  
STATE_Define(AM_Waiting)
{
	// State Action
	E_AM_Status = AM_Waiting ;
	
	// Delay
	GPIO_Delay(500) ;
	
	// Check Event and Update State
		AM_State = STATE(AM_Alarm_OFF);
} 
 
 