/*
 * Pressure_Sensor.h
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

// Declaration State Function of Pressure_Sensor
STATE_Define(PS_Init) ;
STATE_Define(PS_Reading) ;
STATE_Define(PS_Waiting) ;

// State Pointer to function
extern void (*PS_State)() ;




#endif /* PRESSURE_SENSOR_H_ */
