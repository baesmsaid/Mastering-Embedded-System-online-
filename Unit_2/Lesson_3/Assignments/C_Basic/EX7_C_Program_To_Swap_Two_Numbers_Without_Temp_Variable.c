/*
 
===============================================================================================================
=======
 Name        : EX7_C_Program_To_Swap_Two_Numbers_Without_Temp_Variable.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment C-Basic >> EX7_C_Program_To_Swap_Two_Numbers_Without_Temp_Variable using 
Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
int main (void)
{

	int x=30, y=5;

	x=x+y; //x=35
	y=x-y; //y=30
	x=x-y; //x=5
	fflush(stdin); fflush(stdout);
	printf("After Swaping Num1 = %d  Num2 = %d", x,y);
	return 0;

}