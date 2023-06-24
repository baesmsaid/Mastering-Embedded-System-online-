/*
 *    Q_8_C_Function_that_Reverse_an_Input_Array.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *   Description: This c program reverse the elements of an array entered by the user.
 */
 
#include <stdio.h>

void ReverseArr(int arr1[],int arr2[] ,int len);
int main()
{
	int arr1[100],arr2[100];
	int len,i;

	printf("Enter array length : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&len);

	for(i=0;i<len;i++)
	{
		printf("Enter array element [%d] : ",i+1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",&arr1[i]);
	}

	ReverseArr(arr1,arr2,len);

	return 0;
}

void ReverseArr(int arr1[],int arr2[], int len)
{
	int i,j;
	for(i=len-1,j=0 ; i>=0 ; i--,j++)
	{
		arr2[j]=arr1[i];
	}
	for(i=0;i<len;i++)
	{
		fflush(stdin);  fflush(stdout);
		printf("reverse array is [%d] :  %d \n",i+1,arr2[i]);
	}
}
