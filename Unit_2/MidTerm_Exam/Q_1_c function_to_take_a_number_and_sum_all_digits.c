/*
 *   Q_1_c function_to_take_a_number_and_sum_all_digits.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *  Description: program that take a number from user and sum all digits.
 */
 
#include<stdio.h>

void SumOfDigit(int num);

int main()
{
	while(1)
	{
		int num;
		printf("Please enter a positive integer : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&num);
		SumOfDigit(num);
		printf("\n");
	}
	return 0;
}
void SumOfDigit(int num)
{
	int sum=0,digit;
	while (num>0)
	{
		digit=num%10;
		sum=sum+digit;
		num=num/10;
	}
	printf("%d\n",sum);
}

