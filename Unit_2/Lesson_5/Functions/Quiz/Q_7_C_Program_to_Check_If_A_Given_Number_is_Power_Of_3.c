/*
 *   C_Program_to_Check_If_A_Given_Number_is_Power_Of_3.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: Check If Number is Power Of 3 .
 */
 
#include <stdio.h>
#include <stdlib.h>

int check(int num);

int main()
{
    int num, result;
   
    printf("Enter number : \n");
    scanf("%d",&num);
     result = check(num);
     printf("%d==>%d",num,result);
    
    return 0;
}

int check(int num)
{
    while(num % 3 == 0 && num != 1)
    {
        num = num/3;
        if(num == 3)
        return 0;
    }
    return 1;
}

/******************************************** Other Solution ************************************************/

#include "stdio.h"
#include <math.h>
void main()
{
	int number;	
	double result;
	printf("Enter a number:\t");
	scanf("%d",&number);
	result = log(number)/log(3);
	if((result == trunc(result)))
	{
		printf("the number is not a power of 3");
		
	}
	else
	{
		printf("the number is  a power of 3");

	}
}