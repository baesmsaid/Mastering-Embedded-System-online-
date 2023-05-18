/*
 
===============================================================================================================
=======
 Name        : EX5_C_Program_to_Check_a_Character_is_an_Alphabet_or_Not.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >>  EX5_C_Program_to_Check_a_Character_is_an_Alphabet_or_Not using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 #include <stdio.h>

int main() 
{
	while(1)
	{
    char c;
	fflush(stdin); fflush(stdout);
    printf("please enter ur char : \n");
	fflush(stdin); fflush(stdout);
    scanf("%c", &c);

    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("%c is a character \n", c);
    }
    else
    {
        printf("%c is not a character \n", c);
    }
	}
    return 0;
}