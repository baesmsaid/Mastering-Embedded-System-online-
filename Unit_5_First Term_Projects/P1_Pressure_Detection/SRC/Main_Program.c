/*
 * Main_Program.c
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */
 
#include "Main_Program.h"

uint32_t MP_High_Pressure_Detection(void);

// Define Status
enum {
		MP_High_Pressure
 }E_MP_Status;
 
// Declare Variable of Pressure Value
static uint32_t MP_Pressure_Value ;
// Define Thershold Variable
static uint32_t MP_Pressure_Thershold = 20 ;
 
STATE_Define(MP_High_Pressure)
{
	// State Action
	E_MP_Status = MP_High_Pressure ;
	 
	// Read Pressure Value From Pressure Sensor
	MP_Pressure_Value = PS_Get_Pressure_Value() ;
	 
	// Check Event and Update State
	MP_State = STATE(MP_High_Pressure) ;
	 
}
 
// Main Program =====> Alarm Mointor
uint32_t MP_High_Pressure_Detection(void)
{
	return (MP_Pressure_Value > MP_Pressure_Thershold) ;
}	 

 
 