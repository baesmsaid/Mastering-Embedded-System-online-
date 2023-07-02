/*
 ============================================================================
 Name        : C_Program_to_Add_Two_Distances_Systems_Using_Structure.c
 Author      : Basem Said
 Created on  : Jule 2, 2023
 Description : C Program to Add Two Distances Systems Using Structure
 ============================================================================
 */
#include <stdio.h>

struct Sdistance
{
	int feet ;
	float inch ;
}dist1,dist2,Sum;

int main()
{
	printf("Enter Information for 1st distance : \n");
	printf("Enter Feet :  ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&dist1.feet);
	printf("Enter Inch : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&dist1.inch);

	printf("Enter Information for 2st distance : \n");
	printf("Enter Feet :  ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&dist2.feet);
	printf("Enter Inch : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&dist2.inch);

	Sum.feet = dist1.feet + dist2.feet;
	Sum.inch = dist2.inch + dist2.inch;
    /* Changing to feet (feet=12 inch) */
	if(Sum.inch>12.0)
	{
		Sum.inch = Sum.inch - 12.0;
		++Sum.feet;
	}
	printf("Sum Of Distance %d \'- %.1f\" ",Sum.feet,Sum.inch);
	return 0;
}

