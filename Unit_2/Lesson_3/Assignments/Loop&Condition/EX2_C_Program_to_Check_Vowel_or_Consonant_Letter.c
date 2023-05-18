/*
 
===============================================================================================================
=======
 Name        : EX2_C_Program_to_Check_Vowel_or_Consonant_Letter.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >> EX2_C_Program_to_Check_Vowel_or_Consonant_Letter using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
 #include <stdio.h>
int main()
{
 
while (1)
{
	char ch;
	fflush(stdin); fflush(stdout);
    printf("please enter ur char : \n");
	fflush(stdin); fflush(stdout);
    scanf("%c", &ch);
   
    switch(ch)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		case 'A':
		case 'E':
		case 'I':
		case 'O':
		case 'U':
		{
			printf("%c is vowel \n",ch);
		}
		break;
		default:
		{
			printf("%c is Consonant \n",ch);
		}			
	}
}
    
    return 0;
}