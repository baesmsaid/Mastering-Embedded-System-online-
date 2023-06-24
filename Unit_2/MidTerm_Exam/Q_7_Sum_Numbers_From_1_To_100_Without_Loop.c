/*
 *   Q_7_Sum_Numbers_From_1_To_100_Without_Loop_by_Making_User_Defiend_Function.c
 *
 *  Created on: june 24, 2023
 *      Author: Basem Said
 *
 *  Description: program c function to sum numbers from 1 to 100 without loop entered by the user.
 */

#include <stdio.h>
#include <stdlib.h>

int SumNum(int num)
{
	if(num>100)
	{
		return 0;
	}
	else
	{
		return num + SumNum(num+1);
	}

}

int main()
{
	printf("Print Sum Of Numbers From 1 To 100 : %d ",SumNum(1));

	return 0;
}

