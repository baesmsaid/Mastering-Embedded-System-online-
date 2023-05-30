/*
 *   EX3_C_Program_to_Reverse_String_Without_Using_Library_Function.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 
 #include <stdio.h>
#include <string.h>
int main()
{
	char text[10], reverse_text[10];
	int i,j=0;

	/* Assign string */
	printf("Enter a text : \n");
	fflush(stdin); fflush(stdout);
	gets(text);

	/* Getting length. of text */
	for(i=strlen(text); i>0 ;i--)
	{
		reverse_text[j]=text[i-1];
		j++;
	}

	/* Print reverse text */
	fflush(stdin); fflush(stdout);
	printf("reverse text is : %s",reverse_text);

	return 0;
}
