/*
 * lifo.c
 *
 *  Created on: 4/9/2023
 *      Author: Basem
 */

#include "lifo.h"


LIFO_Status LIFO_Add_item (LIFO_Buf_t* lifo_buf , unsigned int item)
{
	// Check Lifo is valid and exist
	if ( !lifo_buf->base || !lifo_buf->head )  // if base OR head not exist
		return LIFO_Null ;

	// Check Lifo is Full
	//if (lifo_buf->head >= (lifo_buf->base + (lifo_buf->lenght * (sizeof(unsigned int))))
	if (lifo_buf->count == lifo_buf->lenght )
		return LIFO_full ;

	// Add/push item after checking last two conditions
	*(lifo_buf->head) = item ;
	lifo_buf->head++ ;  // Increment it to point to next address to add another item
	lifo_buf->count++ ; // Increment counter with head for next item

	return LIFO_no_error;
}

LIFO_Status LIFO_Get_item (LIFO_Buf_t* lifo_buf , unsigned int* item)
{
	// Check Lifo is valid and exist
	if ( !lifo_buf->base || !lifo_buf->head )  // if base OR head not exist
		return LIFO_Null ;

	// Check lifo is empty
	if ( lifo_buf->count == 0 )
		return LIFO_empty;

	lifo_buf->head--; // Back to the item we get.
	*item = *(lifo_buf->head); //get the item
	lifo_buf->count--;

	return LIFO_no_error;
}

LIFO_Status LIFO_Init (LIFO_Buf_t* lifo_buf , unsigned int* buf , unsigned int lenght)
{
	// Check Buffer is valid or not
	if (buf == NULL)
		return LIFO_Null ;

	// initialize all variables of LIFO
	lifo_buf ->base = buf ;
	lifo_buf ->head = buf ;
	lifo_buf ->lenght = lenght ;
	lifo_buf ->count = 0 ;

	return LIFO_no_error;
}
