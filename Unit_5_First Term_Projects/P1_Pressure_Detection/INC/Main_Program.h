/*
 * Main_Program.h
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef MAIN_PROGRAM_H_
#define MAIN_PROGRAM_H_

#include "state.h"

// Declare State Function
STATE_Define(MP_High_Pressure) ;

// State Pointer to Function
extern void (*MP_State)() ;

#endif /* MAIN_PROGRAM_H_ */