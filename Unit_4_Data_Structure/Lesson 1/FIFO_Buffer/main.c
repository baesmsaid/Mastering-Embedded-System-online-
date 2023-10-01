/*
 * main.c
 *
 *  Created on: 12/9/2023
 *      Author: Basem
 */

#include "fifo.h"

void main ()
{
	FIFO_Buf_t FIFO_UART ;    // Create FIFO Uart Buffer
	element_type i , temp;

	if( FIFO_Init( &FIFO_UART , uart_buffer , 5 ) == FIFO_No_Error)
		printf("FIFO Init -------- Done");

	for (i=0 ; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n ",i);
		if( FIFO_Enqueue( &FIFO_UART , i ) == FIFO_No_Error)
			printf(" \t FIFO Enqueue -------- Done \n");
		else
			printf(" \t FIFO Enqueue -------- Failed \n");
	}

	FIFO_Print(&FIFO_UART);
	// Dequeue twice
	if( FIFO_Dequeue( &FIFO_UART , &temp ) == FIFO_No_Error)
		printf(" FIFO Dequeue (%x) \n",temp);
	if( FIFO_Dequeue( &FIFO_UART , &temp ) == FIFO_No_Error)
			printf(" FIFO Dequeue (%x) \n",temp);

	FIFO_Print(&FIFO_UART);

}
