/*
 * Alarm_Actuator.h
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"

// Declare State Fuctions 
STATE_Define(Alarm_Act_Init) ;
STATE_Define(Alarm_Act_Waiting) ;
STATE_Define(Alarm_Act_ON) ;
STATE_Define(Alarm_Act_OFF) ;

// State Pointer to Function
extern void (*Alarm_Act_State)() ;

#endif /* ALARM_ACTUATOR_H_ */