/*
 *    Q_9_C_Function_to_Reverse_a_Words_In_String.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *   Description: This program prints a sentences entered by the user in a reverse order.
 */
 
 #include <stdio.h>
#include <string.h>
void Reverse(char str[])
{
	int i, j, len, startIndex, endIndex;
	len = strlen(str);
	endIndex = len - 1;
	printf("\n *****  Given Word in Reverse   ***** \n");
	for(i = len - 1; i >= 0; i--)
	{
		if(str[i] == ' ' || i == 0)
		{
			if(i == 0)
			{
				startIndex = 0;
			}
			else
			{
				startIndex = i + 1;
			}
			for(j = startIndex; j <= endIndex; j++)
			{
				printf("%c", str[j]);
			}
			endIndex = i - 1;
			printf(" ");
		}
	}

}
int main()
{
	char str[100];
	printf(" Please Enter any Word :  ");
	fflush(stdout); fflush(stdin);
	gets(str);
	Reverse(str);
	return 0;
}