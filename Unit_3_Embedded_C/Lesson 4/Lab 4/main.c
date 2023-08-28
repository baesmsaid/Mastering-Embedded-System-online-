/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Basem Said
 * @brief          : Main program body
 ******************************************************************************
 */

#include <stdint.h>

// register address

#define SYSCTL_RCGC2_R   (*((volatile unsigned long*)0x400FE108))      // Base Address + Offset
#define GPIO_PORTF_DIR_R   (*((volatile unsigned long*)0x40025400))    // Base Address + Offset
#define GPIO_PORTF_DEN_R   (*((volatile unsigned long*)0x4002551C))    // Base Address + Offset
#define GPIO_PORTF_DATA_R   (*((volatile unsigned long*)0x400253FC))   // Base Address + Offset

int main(void)
{
	volatile unsigned long delay_count;
	SYSCTL_RCGC2_R = 0x20;                                    // Enable GPIO_PORT
	for(delay_count=0 ; delay_count<200 ; delay_count++);     // Delay to make sure GPIOF is running and up 
	GPIO_PORTF_DIR_R |= 1<<3 ;                                // Set (PF3) to make direction as output
	GPIO_PORTF_DEN_R |= 1<<3 ;                                // Enable GPIOF Pin
	
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3 ;                                // Set (PF3)
		for(delay_count=0 ; delay_count<200000 ; delay_count++);   // Delay
		GPIO_PORTF_DATA_R &=~(1<<3) ;                              // Clear (PF3)
		for(delay_count=0 ; delay_count<200000 ; delay_count++);   // Delay
	}

	return 0;
}
