/*
 *  EX4_C_Program_To_Insert_An_Element_in_a_Array.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 
 #include <stdio.h>
int main()
{

	int arr[100];
	int n,i, element, location;

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

	/* Assign the element to be inserted */
	printf("Enter the inserted element : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	/* Assign the location */
	printf("Enter the location :\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&location);

	/* Create space at the location */
	for(i=n;i>=location;i--)
	{
		arr[i]=arr[i-1];               /* its like shifting values to add the new value */
	}
	n++;                              /* to add a new element in array we need to expand array */
	arr[location-1]=element;          /* because we start array from 0 */

	/* printing the result */
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}

	return 0;
}
