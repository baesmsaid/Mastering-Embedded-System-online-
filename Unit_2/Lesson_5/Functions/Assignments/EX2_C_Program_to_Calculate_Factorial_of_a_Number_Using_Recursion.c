/*
 *    EX2_C_Program_to_Calculate_Factorial_of_a_Number_Using_Recursion.c
 *
 *  Created on: june 10, 2023
 *      Author: Basem Said
 *
 *  Description: This program calculates the factorial of a specific number entered by the user using recursion.
 */
 
#include <stdio.h>

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Declaration ---------------------------*/
/* ----------------------------------------------------------------------- */

int calcfactorial(int num);

int main()
{
	int num,result;

	printf("ENTER an positive number : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	result=calcfactorial( num);   /* call the function to calculate the factorial */
	printf("Factorial of %d : %d", num, result);  /* print the factorial*/

	return 0;
}

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

int calcfactorial(int num)
{
	if(num==1)
	{
		return 1;
	}
	else
	{
		return num * calcfactorial(num-1); /* getting the factorial using recursion function */
	}
}
