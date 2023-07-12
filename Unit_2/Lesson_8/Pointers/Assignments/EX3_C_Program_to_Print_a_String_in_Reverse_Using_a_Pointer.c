/*
 =========================================================================================
 Name        : C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer.c
 Author      : Basem Said
 Created on  : Jule 11, 2023
 Description : C Program to print a string in reverse using a pointer. 
 =========================================================================================
 */

#include <stdio.h>

int main ()
{
	char str[50], rev[50];
	char *Pstr,*Prev;
	int i=-1; /* to start count string from 0 */

	fflush(stdin); fflush(stdout);
	printf("Enter string : \n");
	fflush(stdin); fflush(stdout);
	scanf("%s",str);

	Pstr=str;
	Prev=rev;
	/* to calculate length of string by pointer */
	while(*Pstr)
	{
		Pstr++;
		i++;
	}
	while(i>=0)
	{
		Pstr--;
		*Prev=*Pstr;
		Prev++;
		i--;
	}
	*Prev='\0' ;
	printf("Reverse of the string is : %s \n",rev);

	return 0;
}