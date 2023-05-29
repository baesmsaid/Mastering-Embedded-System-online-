/*
 *  EX2_C_Program_To_Calculate_Average.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 
 #include <stdio.h>
int main()
{
	float arr[100] , sum=0.0, Avg;
	int i,n;

	fflush(stdin); fflush(stdout);
	printf("Enter number of  elements : \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	while(n>100 || n<=0)
	{
		printf("Error ! Should be in range (1 to 100)\n");
		break;
	}

		fflush(stdin); fflush(stdout);
		for(i=0;i<n;i++)
		{
			fflush(stdin); fflush(stdout);
			printf("Enter your element %d : \n",i+1);
			fflush(stdin); fflush(stdout);
			scanf("%f",&arr[i]);
			sum=sum+arr[i];
		}
		Avg=sum/n;
		printf("The average is : %0.2f \n",Avg);

	return 0;
}