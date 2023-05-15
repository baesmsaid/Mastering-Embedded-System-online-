/*
 
===============================================================================================================
=======
 Name        : EX4_C_Program_to_Multiply_Two_Floating_Point_Numbers.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment >> EX4_C_Program_to_Multiply_Two_Floating_Point_Numbers using Ansi-style 
(c89)
 
===============================================================================================================
=======
 */
 
#include "stdio.h"
#include "stdlib.h"

int main (void)
{

	float num1,num2,multiply;
	printf("please enter ur numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f ", &num1,&num2);
	multiply=num1*num2;
	printf("the multiply is : %f \n",multiply);

	return 0;

}

