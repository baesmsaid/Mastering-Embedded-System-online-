/*
 * US.h
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#ifndef US_H_
#define US_H_

#include "state.h"

//Define States
enum
{
	US_Busy
}US_state_id;

//Declare States Functions US
STATE_define(US_Busy) ;

void US_Init () ;

//STATE Pointer to Function
extern void (*US_state) () ;

#endif /* US_H_ */
