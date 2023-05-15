/*
 
===============================================================================================================
=======
 Name        : EX3_C Program to Add Two Integers.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment >> EX3 C Program to Add Two Integers using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
#include "stdio.h"
#include "stdlib.h"

int main (void)
{

	int num1,num2,sum;
	printf("please enter ur numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%d%d ", &num1,&num2);
	sum=num1+num2;
	printf("the sum is : %d \n",sum);

	return 0;

}