/*
 
===============================================================================================================
=======
 Name        : EX7_C_Program_to_Find_Factorial_of_a_Number.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >> EX7_C_Program_to_Find_Factorial_of_a_Number using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 #include <stdio.h>

int main() 
{
    while(1)
  {
    int num,i,fact=1;
	fflush(stdin); fflush(stdout);
    printf("please enter ur number : \n");
	fflush(stdin); fflush(stdout);
    scanf("%d", &num);

    if (num < 0)
    {
        printf("Error!, there is no factorial for nagative number \n");
    }
    else 
    {
        for (i = 1; i <=num; ++i) 
        {
            fact=fact*i;
        }
        printf("Factorial of %d = %d",num, fact);
    }
  } 
    return 0;
}