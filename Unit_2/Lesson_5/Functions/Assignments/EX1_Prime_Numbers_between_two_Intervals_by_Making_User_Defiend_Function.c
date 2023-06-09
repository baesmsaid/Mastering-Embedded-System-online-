/*
 *   EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function.c
 *
 *  Created on: june 10, 2023
 *      Author: Basem Said
 *
 *  Description: program that find and print the prime numbers between two intervals entered by the user.
 */
/*
 * main.c
 *
 *  Created on: 15/05/2023
 *      Author: Basem
 */
#include <stdio.h>

void PrimeNumbers(int num1 , int num2);  /* Declaring Functions(Functions Prototypes) */

int main()
{
	int num1, num2;

	printf("ENTER two numbers (intervals) : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&num1,&num2);

	PrimeNumbers(num1,num2);

	return 0;
}

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

void PrimeNumbers(int num1 , int num2)
{
	int i, j, count;

	if (num1>num2)  /* if ture we will swap it to get in first number the lower one*/
	{
		int temp;
		temp=num2;
		num2=num1;
		num1=temp;
	}
	fflush(stdin); fflush(stdout);
	printf("prime numbers between %d and %d is : ",num1,num2);

	/* check prime numbers */
	for(i=num1+1;i<num2;i++)
	{
		count=0;
		for(j=1;j<=i;j++)  /*A prime number is a number greater than 1 with only two factors – themselves and 1.*/
		{
			if(i%j==0)
			{
				count++;
			}
		}
		if(count==2)  /* because prime number divide with 2 factors itself and 1 */
		{
			printf("%d ",i);
		}
	}

}
