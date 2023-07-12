/*
 =========================================================================================
 Name        : C_Program_to_Demonstrate_How_to_Handle_the_Pointers_in_the_Program.c
 Author      : Basem Said
 Created on  : Jule 11, 2023
 Description : C Program to demonstrate how to handle the pointers in the program. 
 =========================================================================================
 */

#include <stdio.h>

int main ()
{
	int m=29;
	int *ab=&m;

	fflush(stdin); fflush(stdout);
	printf("Address of m : 0x%p\n", &m);
	printf("value of m : %d\n", m);

	*ab=29;

	printf("Address of ab : 0x%p\n", ab);
	printf("content of ab : %d\n", *ab);

	m=34;

	printf("Address of ab : 0x%p\n", ab);
	printf("content of ab : %d\n", *ab);


	return 0;
}

