/*
 *   Q_6_Return_Unique_Number_In_Array_With_One_Loop_by_Making_User_Defiend_Function.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *  Description: program c function to return unique number in array with one loop entered by the user.
 */
 
 #include <stdio.h>
int GetUniqueNum(int arr[],int len)
{
	int i,unique=0;
	for(i=0;i<len;i++)
	{
		/* The result of XOR is 1 if the two bits are different */
		unique=unique^arr[i];
	}
	return unique;
}
int main()
{
	int arr[100], len,i;
	while(1)
	{
		printf("Please Enter Length of Array : \n");
		fflush(stdout);fflush(stdin);
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
			printf("Please Enter Element of Array [%d] : ",i+1);
			fflush(stdout);fflush(stdin);
			scanf("%d",&arr[i]);
		}

		printf("The Unique Number is : %d",GetUniqueNum(arr,len));
		printf("\n");
	}
	return 0;
}
 
 /***************************************** Other Solution ********************************************************/

#include <stdio.h>
int GetUniqueNum(int arr[],int len)
{
	int i,j,unique,flag;
	for(i=0;i<len;i++)
	{
		flag=0;
		for(j=len;j>=0;j--)
		{
			if(arr[i]==arr[j])
				flag++;
		}
		if(flag==1)
			unique=arr[i];
	}
	return unique;
}
int main()
{
	int arr[100], len,i;
	while(1)
	{
		printf("Please Enter Length of Array : \n");
		fflush(stdout);fflush(stdin);
		scanf("%d",&len);
		for(i=0;i<len;i++)
		{
			printf("Please Enter Element of Array [%d] : ",i+1);
			fflush(stdout);fflush(stdin);
			scanf("%d",&arr[i]);
		}

		printf("The Unique Number is : %d",GetUniqueNum(arr,len));
		printf("\n");
	}
	return 0;
}