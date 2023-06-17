/*
 *    C_Program_for_Swapping_2_Arrays_with_Different_Lenghts.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: A C program to take 2 array with different sizes and swapping it. The main idea of the program
 * 				  is to  prints both arrays before and after swapping to prove the effect of
 * 				  the program's functionality. 
 */
 
#include <stdio.h>


int main()
{
	int arr1[100],arr2[100], temp[100];
	int len1,len2,i;

	printf("Enter array1 length : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&len1);

	printf("Enter array2 length : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&len2);

	/* insert array 1 */
	for(i=0;i<len1;i++)
	{
		printf("Enter array1 element [%d] : ",i+1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",&arr1[i]);
	}
	/* insert array 1 */
	for(i=0;i<len2;i++)
	{
		printf("Enter array2 element [%d] : ",i+1);
		fflush(stdin);  fflush(stdout);
		scanf("%d",&arr2[i]);
	}
	/* print array 1&2 */

	printf("array1 : \n");
	for(i=0;i<len1;i++)
	{
		printf("\t%d : ",arr1[i]);

	}
	printf("\n");
	printf("array2 : \n");
	for(i=0;i<len2;i++)
	{
		printf("\t%d : ",arr2[i]);
	}

	/****** Swapping array  ********/
	/**** if len1 bigger than len2  *****/
	if(len1>len2)
	{
		for(i=0;i<len1;i++)
		{
			temp[i]=arr1[i];
			arr1[i]=arr2[i];
			arr2[i]=temp[i];
		}
		/* print after swapping */
		printf("\n");
		printf("array after swapping \n");

		printf("array1 : \n");
		for(i=0;i<len2;i++)       /* BC Swapping array we Swapping also the length */
		{
			printf("\t%d ",arr1[i]);

		}
		printf("\n");
		printf("array2 : \n");
		for(i=0;i<len1;i++)     /* BC Swapping array we Swapping also the length */
		{
			printf("\t%d ",arr2[i]);
		}
	}
	else
	{
		for(i=0;i<len2;i++)
		{
			temp[i]=arr1[i];
			arr1[i]=arr2[i];
			arr2[i]=temp[i];
		}
		/* print after swapping */
		printf("\n");
		printf("array after swapping \n");

		printf("array1 : \n");
		for(i=0;i<len2;i++)        /* BC Swapping array we Swapping also the length */
		{
			printf("\t%d ",arr1[i]);

		}
		printf("\n");
		printf("array2 : \n");
		for(i=0;i<len1;i++)       /* BC Swapping array we Swapping also the length */
		{
			printf("\t%d ",arr2[i]);
		}
	}
	return 0;
}

