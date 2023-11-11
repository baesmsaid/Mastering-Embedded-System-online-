/*
 * Utilities.h
 *
 *  Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef UTIL_H_
#define UTIL_H_

#define SET_BIT(Reg,BitNum)               Reg |=  (1<<BitNum)
#define RESET_BIT(Reg,BitNum)             Reg &= ~(1<<BitNum)
#define TOGGLE_BIT(Reg,BitNum)            Reg ^=  (1<<BitNum)
#define READ_BIT(Reg,BitNum)              ((Reg) &   (1<<(BitNum)))








#endif /* UTIL_H_ */
