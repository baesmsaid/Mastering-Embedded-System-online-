/*
 *   EX2_C_Program_To_Find_The_Length_of_a_String.c
 *
 *  Created on: May 27, 2023
 *      Author: Basem Said
 */
 
 #include <stdio.h>
int main()
{
	char text[100] ,length=0;
	int i;

	/* Assign string */
	printf("Enter a text : \n");
	fflush(stdin); fflush(stdout);
	gets(text);

	/* Getting length. of text */
	for(i=0; text[i]!='\0';i++)
	{
		length++;
	}

	/* Print length of text */
	printf("length of text is : %d",length);

	return 0;
}
