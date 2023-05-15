/*
 
===============================================================================================================
=======
 Name        : EX5_C_Program_to_Find_ASCII_Value_of_a_Character.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment >> EX5_C_Program_to_Find_ASCII_Value_of_a_Character using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
#include "stdio.h"
#include "stdlib.h"

int main (void)
{

	char c;
	printf("please enter ur char : ");
	fflush(stdin); fflush(stdout);
	scanf("%c", &c);
	printf("the char value is : %d \n",c);

	return 0;

}
