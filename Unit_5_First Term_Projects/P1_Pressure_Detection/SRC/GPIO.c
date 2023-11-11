/*
 * GPIO.c
 *
 * Created on: 27/10/2023
 *      Author: Basem
 */
 
#include "GPIO.h"

void GPIO_Delay(uint32_t nCount)
{
	for(; nCount != 0; nCount--);
}

uint32_t GPIO_GetPressureVal(void){
	return (GPIOA_IDR & 0xFF);
}

void GPIO_Set_Alarm_Actuator(uint32_t i){
	if (i == 1){
		SET_BIT(GPIOA_ODR,13);
	}
	else if (i == 0){
		RESET_BIT(GPIOA_ODR,13);
	}
}

void GPIO_Init (void){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
