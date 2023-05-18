/*
 
===============================================================================================================
=======
 Name        : EX6_C_Program_to_Calculate_Sum_of_Natural_Numbers.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >>  EX6_C_Program_to_Calculate_Sum_of_Natural_Numbers using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 #include <stdio.h>

int main() 
{
	while(1)
  {
    int num, i, sum = 0;
	fflush(stdin); fflush(stdout);
    printf("please enter ur number : \n");
	fflush(stdin); fflush(stdout);
    scanf("%d", &num);

    for (i = 1; i <=num; ++i) 
    {
        sum=sum+i;
    }
    printf("Sum = %d \n", sum);
  }      
    return 0;
}