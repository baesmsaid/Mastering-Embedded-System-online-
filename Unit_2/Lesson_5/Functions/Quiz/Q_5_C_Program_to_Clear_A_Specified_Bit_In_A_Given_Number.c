/*
 *    C_Program_to_Clear_A_Specified_Bit_In_A_Given_Number.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: Clear a specified Bit in number.
 */
 
#include <stdio.h>
#include <stdlib.h>

int Clearbit(int num , int bitnum);

int main(void) 
{
	int num = 0 , bitnum = 0;
	printf("Enter your number : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&num);

	printf("Enter bit position need to clear : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&bitnum);

	printf("Number after clear bit  : %d",Clearbit(num , bitnum));
	return 0;
}

int Clearbit(int num , int bitnum)
{
	num = num & ~(1<<bitnum);

	return num;
}