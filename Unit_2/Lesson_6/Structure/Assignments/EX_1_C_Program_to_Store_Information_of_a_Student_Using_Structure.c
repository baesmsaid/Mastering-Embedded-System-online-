/*
 ============================================================================
 Name        : C_Program_to_Store_Information_of_a_Student_Using_Structure.c
 Author      : Basem Said
 Created on  : Jule 2, 2023
 Description : C Program to Store Information of a Student Using Structure
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

struct SstudentData
{
	char name [50];
	int roll ;
	float mark ;
}S_info;

int main()
{

		fflush(stdin); fflush(stdout);
		printf("Enter Information of students : \n");

		printf("Enter Name :");
		fflush(stdin); fflush(stdout);
		scanf("%s",S_info.name);

		printf("Enter Roll number :  ");
		fflush(stdin); fflush(stdout);
		scanf("%d",&S_info.roll);

		printf("Enter Marks : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&S_info.mark);

		printf("Displaying Information \n");

		printf("Name : %s\n",S_info.name);
		printf("Roll number : %d\n",S_info.roll);
		printf("Mark : %.2f\n",S_info.mark);

	return 0;
}
