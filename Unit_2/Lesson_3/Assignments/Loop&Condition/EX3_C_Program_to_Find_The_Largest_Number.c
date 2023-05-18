/*
 
===============================================================================================================
=======
 Name        : EX3_C_Program_to_Find_The_Largest_Number.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >> EX3_C_Program_to_Find_The_Largest_Number using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
 #include <stdio.h>

int main() 
{
	while(1)
	{
    double num1, num2, num3;
    fflush(stdin); fflush(stdout);
    printf("please enter ur numbers : \n");
	fflush(stdin); fflush(stdout);
    scanf("%lf %lf %lf", &num1, &num2, &num3);

    if (num1 >= num2 && num1 >= num3)
        printf("%.2f is the largest number \n", num1);

    if (num2 >= num1 && num2 >= num3)
        printf("%.2f is the largest number \n", num2);

    if (num3 >= num1 && num3 >= num2)
        printf("%.2f is the largest number \n", num3);
	}

    return 0;
}