/*
 * fifo.h
 *
 *  Created on: 12/9/2023
 *      Author: Basem
 */

#ifndef FIFO_H_
#define FIFO_H_

#include "stdio.h"
#include "stdint.h"

//User Configuration

//Select the element type (unit8_t, unit16_t, unit32_t,....)
#define element_type uint8_t
//Create Buffer 1
#define width1 5
element_type uart_buffer[width1] ;


//FIFO Data Type

typedef struct
{
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;  //Increment while Add/Write Element
	element_type* tail;  //Decrement while Get/Read Element
}FIFO_Buf_t;


typedef enum
{
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null
}FIFO_Buf_Status;


//FIFO APIs

FIFO_Buf_Status  FIFO_Init (FIFO_Buf_t* fifo , element_type* buf , uint32_t length);
FIFO_Buf_Status  FIFO_Enqueue(FIFO_Buf_t* fifo , element_type item );  //Enter Data(item)
FIFO_Buf_Status  FIFO_Dequeue(FIFO_Buf_t* fifo , element_type* item );  //Take Data
FIFO_Buf_Status  FIFO_IS_FULL(FIFO_Buf_t* fifo );
void  FIFO_Print(FIFO_Buf_t* fifo);


#endif /* FIFO_H_ */
