/*
 *    EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 *
 *  Created on: june 10, 2023
 *      Author: Basem Said
 *
 *   Description: This program prints a sentences entered by the user in a reverse order using recursion.
 */
 
 #include <stdio.h>

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Declaration ---------------------------*/
/* ----------------------------------------------------------------------- */

void ReverseSentence();

int main()
{
	/* Asking the user to enter any sentence as reversed */
	printf("ENTER a sentence : \n");
	fflush(stdin); fflush(stdout);
	ReverseSentence();   /* call the function to to reverse the sentence  */

	return 0;
}

/* ----------------------------------------------------------------------- */
/* ---------------------- Functions Definition ----------------------------*/
/* ----------------------------------------------------------------------- */

void ReverseSentence()
{
	char ch;
	scanf("%c",&ch);

	if(ch !='\n') /* to stop the recursion if getting null */
	{
		ReverseSentence(); /*Recursion Function again */
		printf("%c",ch);
	}
}
