/*
 * state.h
 *
 *  Created on: ???/???/????
 *      Author: Basem
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

// Automatic State Function Generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_)  ST_##_statFUN_


//States Connection
void US_Set_distance (int d) ;
void DC_Motor (int s) ;

#endif /* STATE_H_ */
