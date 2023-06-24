/*
 *   Q_5_Count_Number_Of_Ones_In_Binary_Number_by_Making_User_Defiend_Function.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *  Description: program that count number of ones in binary number entered by the user.
 */
 
#include <stdio.h>
void Count1s(int num)
{
	int bit=0, count1 = 0;
	int bin=0;  /* variable to store binary number */

	/* Iterate through all the bits*/
	for (bit=31;bit>=0;bit--)
	{
		bin=num>>bit;
		/* If current bit is 1*/
		if (bin & 1)
		{
			printf("1");
			count1++;
		}
		else
			printf("0");
	}
	printf("\n");
	/* Print the count*/
	printf("Count of Ones in Number is %d\n", count1);
}
int main()
{
	int num;
	while(1)
	{
		printf("Please enter your number  : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&num);
		printf("Binary of %d is : \n",num);
		Count1s(num);
	}
	return 0;
}