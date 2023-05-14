/*
 
===============================================================================================================
=======
 Name        : EX2_C Program to Print a Integer Entered by a User.c
 Author      : Basem Said
 Created on	 : May 14, 2023
 Description : Unit 2 >> Assignment >> EX2 C Program to Print a Integer Entered by a User using Ansi-style (c89)
 
===============================================================================================================
=======
 */

#include "stdio.h"
#include "stdlib.h"

int main (void)
{
	int x;
	printf("please enter ur int : \n");
	fflush(stdout); fflush(stdin);
	scanf("%d",&x);
	printf("ur int is : %d \n",x);

	return 0;

}


