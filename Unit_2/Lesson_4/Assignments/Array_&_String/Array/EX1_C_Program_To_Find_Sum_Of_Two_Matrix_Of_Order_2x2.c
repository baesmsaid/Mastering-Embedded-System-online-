/*
 * EX1_C_Program_To_Find_Sum_Of_Two_Matrix_Of_Order_2x2.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 
#include <stdio.h>
int main()
{
	float arr_1[2][2];
	float arr_2[2][2];
	int i,j;

	printf("Enter your  elements in 1st matrix : \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter element %d %d :",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr_1[i][j]);
		}
	}

	printf("Enter your  elements in 2st matrix : \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("Enter element %d %d :",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr_2[i][j]);
		}
	}
	printf("\n The sum of Matrix \n");
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			fflush(stdin); fflush(stdout);

			arr_1[i][j]=arr_1[i][j]+arr_2[i][j];
			printf("%0.1f ",arr_1[i][j]);
		}
		printf("\n");
	}


	return 0;
}
