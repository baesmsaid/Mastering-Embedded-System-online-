/*
 * Pressure_Sensor.c
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */
 
#include "Pressure_Sensor.h"
 
// Declare Status
enum{
	 
	 PS_Init,
	 PS_Reading,
	 PS_Waiting
}E_PS_Status;
 
//Declare Variable to store Data from Pressure_Sensor
static uint32_t PS_Pressure_Value ;
 
STATE_Define(PS_Init) 
{
	// Initialize Pressure Sensor
	// Call Pressure Sensor Functions
	// State Action
	E_PS_Status = PS_Init ;
	
	// Check Event and Update Status
	PS_State = STATE(PS_Reading) ;
}	

STATE_Define(PS_Reading) 
{
	// State Action
	E_PS_Status = PS_Reading ;
	
	// Read From Pressure Sensor
	PS_Pressure_Value = GPIO_GetPressureVal() ;
	
	// Check Event and Update Status
	PS_State = STATE(PS_Waiting) ;
}
	
STATE_Define(PS_Waiting) 
{
	// State Action
	E_PS_Status = PS_Waiting ;
	
	// Wait to Get Data From Sensor
	GPIO_Delay(1000) ;
	
	// Check Event and Update Status
	PS_State = STATE(PS_Reading) ;
}

//Interface and Set Pressure Value with Main Program
uint32_t PS_Get_Pressure_Value(void)
{
	return PS_Pressure_Value ;
}
