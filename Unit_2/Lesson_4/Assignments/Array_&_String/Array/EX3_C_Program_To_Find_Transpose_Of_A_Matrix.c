/*
 *  EX3_C_Program_To_Find_Transpose_Of_A_Matrix.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 #include <stdio.h>
int main()
{
	int matrix[100][100] ,t_matrix[100][100];
	int row,column,i,j;

	/* take No of rows and columns from user */


	printf("Enter number of  rows : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&row);
	printf("Enter number of  columns : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&column);

	/* Assign elements of matrix */
	fflush(stdin); fflush(stdout);
	printf(" Enter elements of matrix : \n");
	for (i=0;i<row;++i)
	{
		for (j=0;j<column;++j)
		{
			printf("Enter your element matrix %d %d :  ",i+1,j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d",&matrix[i][j]);
		}
	}

	/* Displaying matrix[][] */
	fflush(stdin); fflush(stdout);
	printf(" Entered matrix is : \n");
	for (i=0;i<row;++i)
	{
		for (j=0;j<column;++j)
		{
			fflush(stdin); fflush(stdout);
			printf(" %d",matrix[i][j]);
		}
		printf("\n");
	}

	/* transpose matrix[][] and storing in t_matrix[][] */
	for (i=0;i<row;++i)
	{
		for (j=0;j<column;++j)
		{
			t_matrix[j][i] = matrix[i][j];
		}
	}

	/* Displaying transpose t_matrix[][] */

	printf(" transpose matrix is : \n");
	for (i=0;i<column;++i)
	{
		for (j=0;j<row;++j)
		{

			printf(" %d",t_matrix[i][j]);
		}
		printf("\n\n");
	}


	return 0;
}