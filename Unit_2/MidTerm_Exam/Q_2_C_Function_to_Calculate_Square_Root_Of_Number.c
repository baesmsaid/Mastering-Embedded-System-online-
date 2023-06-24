/*
 *    Q_2_C_Function_to_Calculate_Square_Root_Of_Number.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *   Description: This program calculate square root of number.
 */


#include <stdio.h>

void Sqrt(float num);

int main()
{
	float num;
	while(1)
	{
		printf("Enter the number: ");
		fflush(stdout); fflush(stdin);
		scanf("%f", &num);
		Sqrt(num);
		printf("\n");
	}
	return 0;
}

void Sqrt(float num)
{
	float precision = 0.001;
	float new_num = num;
	while(num * num- new_num > precision)
	{
		num = (num + (new_num / num)) / 2;
	}
	printf("The Square Root of %.3f  is  %.3f ", new_num, num);
}
