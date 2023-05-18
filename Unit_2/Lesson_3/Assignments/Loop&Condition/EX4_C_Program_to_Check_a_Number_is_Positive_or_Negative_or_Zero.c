/*
 
===============================================================================================================
=======
 Name        : EX4_C_Program_to_Check_a_Number_is_Positive_or_Negative_or_Zero.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >> EX4_C_Program_to_Check_a_Number_is_Positive_or_Negative_or_Zero using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 #include <stdio.h>

int main() 
{
	while(1)
	{
    float num;
	fflush(stdin); fflush(stdout);
    printf("please enter a number : \n");
	fflush(stdin); fflush(stdout);
    scanf("%f", &num);

    if (num <= 0) 
    {
        if (num == 0)
        {
            printf("%f is zero \n",num);
        }
        else
        {
            printf("%f is negative \n",num);
        }  
    } 
    else
    {
        printf("%f is positive \n",num);
    }
	}
    return 0;
}