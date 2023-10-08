/*
 * lifo.h
 *
 *  Created on: 4/9/2023
 *      Author: Basem
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "stdint.h"
#include "stdlib.h"

//type definitions

typedef struct
{
	unsigned int lenght ;
	unsigned int count ;
	unsigned int* base ;
	unsigned int* head ;
}LIFO_Buf_t;

//Enum of Status

typedef enum
{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null       //LIFO Not Found
}LIFO_Status;

//APIs

LIFO_Status LIFO_Add_item (LIFO_Buf_t* lifo_buf , unsigned int item);  // take Lifo_Buffer_Name &Data and return Status
LIFO_Status LIFO_Get_item (LIFO_Buf_t* lifo_buf , unsigned int* item);
LIFO_Status LIFO_Init (LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int lenght);    // take Lifo_Buffer_Name & Array of buffer

#endif /* LIFO_H_ */
