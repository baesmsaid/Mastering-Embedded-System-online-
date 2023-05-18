/*
 
===============================================================================================================
=======
 Name        : EX1_C_Program_to_Check_a_Number_Is_Even.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >> EX1_C_Program_to_Check_a_Number_Is_Even using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
 #include <stdio.h>
int main()
{
    int x;
while (1)
{
	fflush(stdin); fflush(stdout);
    printf("please enter ur number : \n");
	fflush(stdin); fflush(stdout);
    scanf("%d", &x);
    fflush(stdin); fflush(stdout);
    if(x & 1 == 1)
	{
        printf("%d is odd \n", x);
	}
    else
	{
        printf("%d is even \n", x);
	}
}
    
    return 0;
}