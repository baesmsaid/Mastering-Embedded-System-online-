/*
 *    C_Program_to_Know_The_Value_Of_4th_Least_significant_Bit_In_Binary.c
 *
 *  Created on: june 16, 2023
 *      Author: Basem Said
 *
 *   Description: Know The Value Of 4th Least significant Bit In Binary.
 */
 
 #include <stdio.h>

int main(void)
{
	int num,bit,result;
	
	printf("Please enter the number :\n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&num);
	
	/* convert number to binary */
	printf("%d in binary system is :",num);
	for(bit=31;bit>=0;bit--)
	{
		result = num>>bit;
		
		/* print the binary */
		if(result&1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	
	/* print 4th least significant bit */
	result = num>>3;
	if(result&1)
		printf("4th least significant bit is 1");
	else
		printf("4th least significant bit is 0");

	return 0;
}
