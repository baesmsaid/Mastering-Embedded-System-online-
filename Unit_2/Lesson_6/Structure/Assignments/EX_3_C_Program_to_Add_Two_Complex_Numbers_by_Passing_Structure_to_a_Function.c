/*
 =========================================================================================
 Name        : C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function.c
 Author      : Basem Said
 Created on  : Jule 2, 2023
 Description : C Program to Add Two Complex Number by Passing Structure to Function 
 =========================================================================================
 */
#include <stdio.h>

struct SComplexNum
{
	float real ;
	float imaginary ;
}C1,C2,C_Sum;

void AddComplex(struct SComplexNum C1,struct SComplexNum C2)
{
	C_Sum.real = C1.real + C2.real ;
	C_Sum.imaginary = C1.imaginary + C2.imaginary ;

	printf("Sum = %.1f + %.1fi",C_Sum.real,C_Sum.imaginary);
}
int main()
{
	printf("For 1st Complex Number : \n");
	printf("Enter Real and Imaginary Number :  ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&C1.real,&C1.imaginary);

	printf("For 2st Complex Number : \n");
	printf("Enter Real and Imaginary Number :  ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&C2.real,&C2.imaginary);

	AddComplex(C1,C2);

	return 0;
}
