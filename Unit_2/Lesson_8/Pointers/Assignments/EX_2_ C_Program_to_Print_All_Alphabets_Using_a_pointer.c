/*
 =========================================================================================
 Name        : C_Program_to_Print_All_Alphabets_Using_a_pointer.c
 Author      : Basem Said
 Created on  : Jule 11, 2023
 Description : C Program to print all the alphabets using a pointer. 
 =========================================================================================
 */

#include <stdio.h>

int main ()
{
	char Alphabets[27];
	char *ptr;
	int i;

	fflush(stdin); fflush(stdout);
	printf("print all Alphabets by pointer : \n");
	 /* pointer to array */
	ptr = Alphabets ;
/* loop to assign Alphabets in pointer and print it */
	for(i=0;i<26;i++)
	{
		*ptr = i + 'A';
		printf("  %c  ",*ptr);
		ptr++;
	}


	return 0;
}
