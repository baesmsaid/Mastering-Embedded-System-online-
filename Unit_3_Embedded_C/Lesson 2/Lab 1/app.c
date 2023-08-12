#include "uart.h"

unsigned char string_buffer[100] = "learn-in-depth:Basem" ;
unsigned char const string_buffer2[100] = "learn-in-depth:Basem" ; // to create Rodata section 

void main(void)
{
	Uart_Send_string (string_buffer); // send first element   
}	                                                                                                                                                                                                                                                                                                                                                                                                                                                              