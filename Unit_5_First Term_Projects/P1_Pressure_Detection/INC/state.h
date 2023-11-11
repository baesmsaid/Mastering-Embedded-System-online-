/*
 * state.h
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef STATE_H_
#define STATE_H_

#include "GPIO.h"

// Automatic State Function Generated
#define STATE_Define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_)  ST_##_statFUN_


//States Connection

// Pressure Sensor =====> Main Program
uint32_t PS_Get_Pressure_Value (void) ;

//Alaram Actuator =====> Alaram Monitor
void AA_Start_Alarm (void) ;
void AA_Stop_Alarm (void) ;

//Main Program =====> Alaram Monitor
uint32_t MP_High_Pressure_Detection (void) ;

#endif /* STATE_H_ */
