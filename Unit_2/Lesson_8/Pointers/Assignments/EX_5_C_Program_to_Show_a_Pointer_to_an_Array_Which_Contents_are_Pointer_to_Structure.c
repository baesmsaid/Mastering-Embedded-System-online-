/*
 =================================================================================================
 Name        : C_Program_to_Show_a_Pointer_to_an_Array_Which_Contents_are_Pointer_to_Structure.c
 Author      : Basem Said
 Created on  : Jule 11, 2023
 Description : C Program to show a pointer to an array which contents are pointer to structure. 
 =================================================================================================
 */
 
 #include <stdio.h>

struct SEmployee
{
	char *name;
	int ID;
};

int main ()
{
	struct SEmployee emp1={"Bassem",25}, emp2={"Said",40} , emp3={"Mohamed",55};

	struct SEmployee *arr[]={&emp1,&emp2,&emp3}; /*pointer to array have 3 addresses of struct employee*/

	struct SEmployee *(*pt_arr)[3]=&arr; /*pointer to pointer to struct have address of first element in array */

	fflush(stdin); fflush(stdout);
	printf("Employee Name : %s \n",(*(*pt_arr))->name);
	printf("Employee ID : %d \n",(*(*pt_arr))->ID);


	return 0;
}
