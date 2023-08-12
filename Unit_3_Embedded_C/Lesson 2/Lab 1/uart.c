#include "uart.h"
#define UART0DR  *((volatile unsigned int*const)((unsigned int*)0x101f1000)) 

void Uart_Send_string (unsigned char* P_tx_sting)
{
	while(*P_tx_sting != '\0') // P_tx_sting is a pointer point to frist element and check if is not equal null 
	{
		UART0DR = (unsigned int)(*P_tx_sting); //assign string with casting(bc uart is int) in Uart
	    P_tx_sting++; // to assign next character
	}	
	
	
}	
