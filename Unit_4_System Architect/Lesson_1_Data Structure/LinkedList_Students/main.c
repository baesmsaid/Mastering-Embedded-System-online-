/*
 * main.c
 *
 *  Created on: 17/9/2023
 *      Author: Basem
 */

#include "Students.h"


void main ()
{
	char Option [40] ;
	int count = 0 ;
	while (1)
	{
		DPRINTF("\n =====================") ;
		DPRINTF("\n\t Choose on of the following Options \n") ;
		DPRINTF("\n 1: Add Student") ;
		DPRINTF("\n 2: Delete Student") ;
		DPRINTF("\n 3: View Student") ;
		DPRINTF("\n 4: Delete All") ;
		DPRINTF("\n 5: Get Node") ;
		DPRINTF("\n 6: Get Length Iterative") ;
		DPRINTF("\n 7: Get Length Recursive") ;
		DPRINTF("\n 8: Get Node From The End") ;
		DPRINTF("\n 9: Get Middle student") ;
		DPRINTF("\n 10: Detect Loop") ;
		DPRINTF("\n 11: Reverse List") ;
		DPRINTF("\n Enter Option Number : ") ;

		gets (Option) ;
		DPRINTF("\n =====================") ;
		switch (atoi (Option))
		{
		case 1:
			AddStudent() ;
			break ;
		case 2:
			DeleteStudent() ;
			break ;
		case 3:
			ViewStudent() ;
			break ;
		case 4:
			DeleteAll() ;
			break ;
		case 5:
			GetNode () ;
			break ;
		case 6:
			GetLength_Iterative () ;
			break ;
		case 7:
			count = GetLength_Recursive (gpFirstStudent) ;
			DPRINTF ("\n Number of Nodes is : %d ", count) ;
			break ;
		case 8:
			GetNode_From_End () ;
			break ;
		case 9:
			GetMiddle_Student () ;
			break ;
		case 10:
			DetectLoop () ;
			break ;
		case 11:
			ReverseList () ;
			break ;
		default:
			DPRINTF("\n Wrong Option") ;
			break ;
		}

	}
}
