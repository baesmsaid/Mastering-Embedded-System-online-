/*
 *   C_Program_to_Return_The_index_of_The_Last_Occurrence_of_A_Number_In_A_Given_Array.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: Return Index of The Last Occurrence Of Number In Array.
 */
 
#include <stdio.h>
#include <stdlib.h>

int LastOccurrence(int arr[], int len);

int main()
{
	int arr[100];
	int len,last;

	printf("Enter array length : \n");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&len);

	int i;
	for(i=0;i<len;i++)
	{

		printf("Enter array element [%d] : \n",i+1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",&arr[i]);
	}

	last = LastOccurrence(arr,len);
	printf(" last occurrence is %d",last);

	return 0;
}

int LastOccurrence(int arr[], int len)
{
	int i,index;
	printf("enter the number you want to find :");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&index);

	for(i=len; i>0; i--)
	{
		if(arr[i]==index)
			return i+1;
	}
	return -1;
}