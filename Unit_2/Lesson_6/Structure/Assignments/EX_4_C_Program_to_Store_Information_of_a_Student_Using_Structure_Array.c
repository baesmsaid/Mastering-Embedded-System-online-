/*
 ==================================================================================
 Name        : C_Program_to_Store_Information_of_a_Student_Using_Structure_Array.c
 Author      : Basem Said
 Created on  : Jule 2, 2023
 Description : C Program to Store Information of a Student Using Structure Array
 ==================================================================================
 */

#include <stdio.h>
#include <string.h>
#include <conio.h>

struct SstudentData
{
	char name [50];
	int roll ;
	float mark ;
}S_info[10];

int main()
{
	int count = 0 ;
	S_info->roll=0;
	fflush(stdin); fflush(stdout);
	
	printf("Enter Information of students : \n");
	do
	{
		printf("For Roll number : %d  \n",S_info->roll+1);
		fflush(stdin); fflush(stdout);
		S_info->roll++;

		printf("Enter Name :");
		fflush(stdin); fflush(stdout);
		scanf("%s",S_info[count].name);

		printf("Enter Marks : ");
		fflush(stdin); fflush(stdout);
		scanf("%f",&S_info[count].mark);
		
		count ++;
	}while(count!=10);

	printf("Displaying Information \n");

	for(S_info->roll=0;S_info->roll<count;S_info->roll++)
	{
		printf("For Roll number : %d  \n",S_info->roll+1);
		printf("Name : %s\n",S_info[S_info->roll].name);
		printf("Mark : %.2f\n",S_info[S_info->roll].mark);
	}
	return 0;
}

