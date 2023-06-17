/*
 *    C_Program_to_Convert_A_Decimal_Number_Stored_As_An_ASCII_Array_to_An_Unsigned_Integer.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: To Convert A Decimal Number Stored As An ASCII Array to An Unsigned Integer.
 */
 
#include <stdio.h>
#include <stdlib.h>

void ArrayEntery(char arr[],int len);
int arrtoint(char arr[],int len);

int main()
{
	char arr[100];
	int result,len;

	printf("Enter array length : ");
	fflush(stdin);  fflush(stdout);
	scanf("%d",&len);

	ArrayEntery(arr,len);

	result = arrtoint(arr,len);
	printf("number = %u",result);
	return 0;
}
void ArrayEntery(char arr[], int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		printf("enter ur element [%d] \n",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%c",&arr[i]);
	}
}

int arrtoint(char arr[], int len)
{
	int i;
	int value = 0 , num = 0;

	for(i=0;i<len;i++)
	{
		value = value*10;
		num = arr[i]-'0';
		value = value + num;
	}
	return value;
}
