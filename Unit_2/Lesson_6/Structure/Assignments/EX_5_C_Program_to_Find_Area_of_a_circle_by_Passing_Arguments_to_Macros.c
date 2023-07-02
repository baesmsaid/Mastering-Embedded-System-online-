/*
 ==================================================================================
 Name        : C_Program_to_Find_Area_of_a_circle_by_Passing_Arguments_to_Macros.c
 Author      : Basem Said
 Created on  : Jule 2, 2023
 Description : C Program to Find Area of a Circle by Passing Arguments to Macros
 ==================================================================================
 */
#include <stdio.h>

#define PI 3.14
#define Area(R) PI*R*R

int main()
{
	float R,Area;
	fflush(stdin);fflush(stdout);
	printf("Enter Radius of Circle : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&R);
	Area = Area(R);
	printf("The Area of Circle = %.2f",Area);

	return 0;
}
