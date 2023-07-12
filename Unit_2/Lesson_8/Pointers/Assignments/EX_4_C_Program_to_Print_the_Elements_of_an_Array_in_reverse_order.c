/*
 =========================================================================================
 Name        : C_Program_to_Print_the_Elements_of_an_Array_in_reverse_order.c
 Author      : Basem Said
 Created on  : Jule 11, 2023
 Description : C Program to print the elements of an array in reverse order. 
 =========================================================================================
 */
 
#include <stdio.h>

int main ()
{
	int arr[50],num,i;
	int *ptr;

	printf("Enter Number of elements in array : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);

	ptr=arr;

	fflush(stdin); fflush(stdout);
	printf("Enter elements in array : \n");
	for(i=0;i<num;i++)
	{
		printf("Enter element [%d] : ",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d",ptr);
		ptr++;
	}

	ptr=&arr[num-1];
	
	printf("The elements of array in reverse order are : \n");
	for(i=num;i>0;i--)
	{
		printf("element [%d] : %d \n",i,*ptr);
		ptr--;
	}

	return 0;
}
