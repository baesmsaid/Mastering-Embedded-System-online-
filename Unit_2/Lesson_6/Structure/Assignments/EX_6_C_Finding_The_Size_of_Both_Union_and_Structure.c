/*
 ==================================================================================
 Name        : C_Finding_The_Size_of_Both_Union_and_Structure.c
 Author      : Basem Said
 Created on  : Jule 2, 2023
 Description : C Program to Find Size of Both Union and Structure
 ==================================================================================
 */
#include <stdio.h>

union UnionJob
{
	char name [32] ;
	float salary;
	int worker_no;

} U;

struct Job
{
	char name [32];
	float salary;
	int worker_no;

} S;

int main ()
{
	printf ("Size of the union is: %d", sizeof (U));
	printf ("\nSize of the structure is: %d", sizeof (S));

	return 0;
}
