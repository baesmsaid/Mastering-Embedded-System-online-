/*
 *    Q_10_C_Function_to_Count_The_Max_Number_Of_Ones_Between_Two_Zeros.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *   Description: This program count max number of ones between two zeros.
 */
 
#include <stdio.h>
void Max1sBtw0s(int num)
{
	int bit=0, count1 = 0, max_ones=0;
	int bin_num=0;  /* variable to store binary number */

	/* Iterate through all the bits*/
	for (bit=31;bit>=0;bit--)
	{
		bin_num=num>>bit;
		/* If current bit is 1*/
		if (bin_num & 1)
		{
			printf("1");
			count1++;
		}
		else
		{
			printf("0");
			if(count1>max_ones)
			{
				max_ones=count1;
				count1=0;
			}
		}
	}
	printf("\n");
	/* Print the max*/
	printf("Max of Ones in Number Between Two Zeros is  %d\n", max_ones);
}
int main()
{
	int num;
	while(1)
	{
		printf("Please Enter your number  : ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&num);
		printf("Binary of %d is : \n",num);
		Max1sBtw0s(num);
	}
	return 0;
}
