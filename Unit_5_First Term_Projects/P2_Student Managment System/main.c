/*
 * main.c
 *
 *  Created on: 26/11/2023
 *      Author: Basem
 */

#include "Student_Sys_Queue.h"

#define Students_Number 50

int main (void)
{
	int Option ;
	FIFO_Buf_t students ;
	struct SStudent_Info Students_Buf[Students_Number] ;

	Students_Init(&students , Students_Buf , Students_Number) ;
	DPRINTF("Welcome to The Student Management System\n") ;
	DPRINTF("\n Do you want to Recover Last DataBase ?!\n") ;
	DPRINTF("\t 1: Yes \n \t 2: No \n") ;
	DPRINTF("Enter your Option: ") ;
	scanf("%d",&Option) ;

	switch (Option)
	{
		case 1:
			Add_Student_From_Update_File(&students) ;
			break ;
		case 2:
			break ;
		default:
			break ;
	}


	while(1)
	{
		DPRINTF(" ***********************\n") ;
		DPRINTF("\n Choose the Following Options") ;
		DPRINTF("\n\t 1: Add Student Manually") ;
		DPRINTF("\n\t 2: Add Student From Text File") ;
		DPRINTF("\n\t 3: Get Student by Roll Number") ;
		DPRINTF("\n\t 4: Get Student by First Name") ;
		DPRINTF("\n\t 5: Get Student by Course ID") ;
		DPRINTF("\n\t 6: Print Students Number") ;
		DPRINTF("\n\t 7: Delete Student by Roll Number") ;
		DPRINTF("\n\t 8: Update Student by Roll Number") ;
		DPRINTF("\n\t 9: View Students") ;
		DPRINTF("\n\t 10: Update Students File") ;
		DPRINTF("\n\t 11: Exit") ;

		DPRINTF("\n\n Enter Your Option") ;
		scanf("%d",&Option) ;
		DPRINTF(" *************************\n") ;

		switch (Option)
		{
			case 1:
				Add_Student_Manually(&students) ;
				break ;
			case 2:
				Add_Student_From_File(&students) ;
				break ;
			case 3:
				Get_Student_by_RollNum(&students) ;
				break ;
			case 4:
				Get_Student_by_FirstName(&students) ;
				break ;
			case 5:
				Get_Student_by_CourseId(&students) ;
				break ;
			case 6:
				Print_StudentsNum(&students) ;
				break ;
			case 7:
				Delete_Student_by_RollNum(&students) ;
				break ;
			case 8:
				Update_Student_by_RollNum(&students) ;
				break ;
			case 9:
				Show_Students_Info(&students) ;
				break ;
			case 10:
				Update_Student_File(&students) ;
				break ;
			case 11:
				DPRINTF("\n\t Thank You For Using Our System") ;
				return 0 ;
			default:
				DPRINTF("\n Wrong Option: Try Again \n\n") ;
				break ;
		}
	}
	return 0 ;
}
