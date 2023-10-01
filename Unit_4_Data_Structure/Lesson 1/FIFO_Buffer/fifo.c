/*
 * fifo.c
 *
 *  Created on: 12/9/2023
 *      Author: Basem
 */

#include "fifo.h"

//FIFO APIs

FIFO_Buf_Status  FIFO_Init (FIFO_Buf_t* fifo , element_type* buf , uint32_t length)
{
	// Check FIFO is exist
	if (buf == NULL)
		return FIFO_Null ;

	// Initialize FIFO Buffer

	fifo->base = buf ;
	fifo->head = buf ;
	fifo->tail = buf ;
	fifo->length = length ;
	fifo->count = 0 ;

	return FIFO_No_Error ;

}
FIFO_Buf_Status  FIFO_Enqueue(FIFO_Buf_t* fifo , element_type item )
{
	if ( !fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null ;

	// Check fifo is full
	if (FIFO_IS_FULL (fifo) == FIFO_Full)
		return FIFO_Full;

	//Add Item
	*(fifo->head) = item ;
	fifo->count++ ;

	//Circler FIFO
	//Check if the head is in the End of Array
	if(fifo->head == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->head = fifo->base ;    // return head to start of Array
	else
		fifo->head++ ;    // Increment the head

	return FIFO_No_Error ;

}
FIFO_Buf_Status  FIFO_Dequeue(FIFO_Buf_t* fifo , element_type* item )
{
	if ( !fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null ;

	// Check fifo is empty
	if (fifo->count == 0)
		return FIFO_Empty ;
	// Get Item
	*item = *(fifo->tail) ;
	fifo->count-- ;

	//Check if the tail is in the End of Array
	if(fifo->tail == (fifo->base + (fifo->length * sizeof(element_type))))
		fifo->tail = fifo->base ;    // return tail to start of Array
	else
		fifo->tail++ ;    // Increment the tail

	return FIFO_No_Error ;
}
FIFO_Buf_Status  FIFO_IS_FULL(FIFO_Buf_t* fifo )
{

	if ( !fifo->base || !fifo->head || !fifo->tail)
		return FIFO_Null ;

	// Check fifo is full
	if (fifo->count == fifo->length)
		return FIFO_Full ;
	// if fifo is exist and not full
	return FIFO_No_Error ;

}
void  FIFO_Print(FIFO_Buf_t* fifo)
{
	//Create temp as pointer to avoid manipulating with tail or any data in fifo
	element_type* temp ;
	int i ;

	if (fifo->count == 0)
		printf ("FIFO is Empty \n");
	else
	{
		temp = fifo->tail ;
		printf ("\n ======== FIFO_Print ======= \n") ;
		//Loop to read every data in fifo
		for (i=0 ; i< fifo->count ; i++)
		{
			printf ("\t %x \n", *temp) ;
			temp++ ;
		}
		printf ("\n ======== Done ======= \n") ;
	}

}
