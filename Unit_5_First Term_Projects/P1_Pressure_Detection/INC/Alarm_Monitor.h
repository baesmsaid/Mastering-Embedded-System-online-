/*
 * Alarm_Monitor.h
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

// Declare State Function
STATE_Define(AM_Alarm_OFF) ;
STATE_Define(AM_Alarm_ON) ;
STATE_Define(AM_Waiting) ;

// State Pointer to Function
extern void (*AM_State)() ;

#endif /* ALARM_MONITOR_H_ */