/*
 *   Q_4_Revers_Digits_In_Number_by_Making_User_Defiend_Function.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *  Description: program that find and print the prime numbers between two intervals entered by the user.
 */
 #include <stdio.h>

/* Iterative function to reverse digits of number */
int ReverseDigits(int num)
{
	int rev_num = 0;
	while (num > 0) {
		rev_num = rev_num * 10 + num % 10;
		num = num / 10;
	}
	return rev_num;
}

/* Test ReverseDigits */
int main()
{
	while(1)
	{
	int num;
	printf("Please enter your number  : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	printf("Reverse of no. is %d\n", ReverseDigits(num));
	}

	return 0;
}