/*
 * Alarm_Actuator.c
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */
 
#include "Alarm_Actuator.h"

// Define Status
enum {
		Alarm_Act_Init,
		Alarm_Act_Waiting,
		Alarm_Act_ON,
		Alarm_Act_OFF
  }E_Alarm_Act_Status ;
  
STATE_Define(Alarm_Act_Init)
{
	// Initialize The Alarm Actuator
	// Call The Alarm Actuator Driver Function	
	// State Action
	E_Alarm_Act_Status = Alarm_Act_Init ;
	
	// Check Event and Update State
	Alarm_Act_State = STATE(Alarm_Act_Waiting) ;
}

STATE_Define(Alarm_Act_Waiting)
{
	// State Action
	E_Alarm_Act_Status = Alarm_Act_Waiting ;
}

STATE_Define (Alarm_Act_ON)
{
	// State Action
	E_Alarm_Act_Status = Alarm_Act_ON ;
	
	// Start Alarm Actuator
	GPIO_Set_Alarm_Actuator(TRUE) ;
	
	// Check Event and Update State
	Alarm_Act_State = STATE(Alarm_Act_Waiting) ;
}

STATE_Define (Alarm_Act_OFF)
{
	// State Action
	E_Alarm_Act_Status = Alarm_Act_OFF ;
	
	// Start Alarm Actuator
	GPIO_Set_Alarm_Actuator(FALSE) ;
	
	// Check Event and Update State
	Alarm_Act_State = STATE(Alarm_Act_Waiting) ;
}
 
void AA_Start_Alarm(void)
{
	// Update State	
	Alarm_Act_State = STATE(Alarm_Act_ON) ;
}
 
void AA_Stop_Alarm(void)
{
	// Update State	
	Alarm_Act_State = STATE(Alarm_Act_OFF) ;
}
 
 
 
 
 
 