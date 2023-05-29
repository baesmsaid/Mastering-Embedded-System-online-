/*
 *   EX5_C_Program_To_Search_an_Element_In_Array.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 #include <stdio.h>
int main()
{

	int arr[100];
	int n,i, element;

	/* Assign No. of elements */
	printf("Enter No. of elements : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);

	/* Assign elements values */
	for(i=0;i<n;i++)
	{
		fflush(stdin); fflush(stdout);
		scanf("%d",&arr[i]);
	}

	/* Assign the element to be searched */
	printf("Enter the searched element : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	/* finding the location of searched element */
	for(i=0;i<n;i++)
	{
		if(arr[i]==element)
		{
			printf("the location of searche element is : %d",i+1);
			break;
		}
	}
