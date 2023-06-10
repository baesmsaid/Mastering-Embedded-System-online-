/*
 *    EX4_C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion.c
 *
 *  Created on: june 10, 2023
 *      Author: Basem Said
 *
 *   Description: This program calculates the power of a number using recursion. 
 */
 
 #include <stdio.h>

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Declaration ---------------------------*/
/* ----------------------------------------------------------------------- */

int Power(int base, int power);

int main()
{
	int base, power;
	/* Asking the user to enter any base number and the power */
	printf("ENTER base number : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&base);
	printf("ENTER power number (positive number) : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&power);
	Power(base,power);   /* call the function to to reverse the sentence  */
	printf ("%d^%d = %d", base, power, Power(base,power));	/* print the result using function recursion */

	return 0;
}

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

int Power(int base, int power)
{
	if(power==0) /* case power of zero */
		return 1;
	else if(power==1) /* case power of one */
		return base;
	else
		return base * Power(base,power-1); /* power calculation */
}
