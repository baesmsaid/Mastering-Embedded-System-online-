/*
 *   EX1_C_Program_To_Find_The_Frequency_Of_Characters.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
#include <stdio.h>
int main()
{
	char text[100] ,ch,counter=0;
	int i;

	/* Assign string */
	printf("Enter a text : \n");
	fflush(stdin); fflush(stdout);
	gets(text);

	/* Assign character to find it */
	printf("Enter a character to find it : \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&ch);

	/* Getting freq. of character */
	for(i=0; i < sizeof(text);i++)
	{
		if(text[i]==ch)
		{
			counter++;
		}
	}

	/* Print freq. of character */
	printf("Frequency of %c : %d",ch,counter);

	return 0;
}
