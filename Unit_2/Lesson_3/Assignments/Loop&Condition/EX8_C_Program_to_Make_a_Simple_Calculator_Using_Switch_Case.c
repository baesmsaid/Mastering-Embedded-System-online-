/*
 
===============================================================================================================
=======
 Name        : EX8_C_Program_to_Make_a_Simple_Calculator_Using_Switch_Case.c
 Author      : Basem Said
 Created on	 : May 15, 2023
 Description : Unit 2 >> Assignment Loop&Condition >> EX8_C_Program_to_Make_a_Simple_Calculator_Using_Switch_Case using Ansi-style (c89)
 
===============================================================================================================
=======
 */
 
 #include <stdio.h>
int main()
{
	char op ;
	float x,y,r;

	while(1)
	{
		fflush(stdin); fflush(stdout);
		printf("Enter two operands: \n");
		fflush(stdin); fflush(stdout);
		scanf("%f%f",&x,&y);
		fflush(stdin); fflush(stdout);
		printf("Enter an operator (+, -, *, /): \n");
		fflush(stdin); fflush(stdout);
		scanf("%c",&op);

		switch(op)
		{
		case '+' :
			r=x+y;
			break;

		case '-' :
			r=x-y;
			break;

		case '*' :
			r=x*y;
			break;

		case '/' :
			r=x/y;
			break;

		default :
			printf("Error\n");

		}
		printf("Result = %f \n",r);
	}

	return 0;
}
