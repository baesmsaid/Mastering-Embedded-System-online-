/*
 
===============================================================================================================
=======
 Name        : EX6_C_Program_to_Swap_Two_Numbers.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment >> EX6_C_Program_to_Swap_Two_Numbers using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
#include "stdio.h"


int main (void)
{

	float num1, num2, temp;
	fflush(stdin); fflush(stdout);
	printf("please enter ur number1 : \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num1);
	fflush(stdin); fflush(stdout);
	printf("please enter ur number2 : \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&num2);
	fflush(stdin); fflush(stdout);
	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("the numbers after swap is : %f  %f \n",num1,num2);

	return 0;

}

