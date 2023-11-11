/*
 * GPIO.h
 *
 * Created on: 27/10/2023
 *      Author: Basem
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "Platform_Types.h"
#include "Util.h"

#define GPIO_PORTA 0x40010800
#define BASE_RCC   0x40021000

#define APB2ENR   *(volatile uint32_t *)(BASE_RCC + 0x18)

#define GPIOA_CRL *(volatile uint32_t *)(GPIO_PORTA + 0x00)
#define GPIOA_CRH *(volatile uint32_t *)(GPIO_PORTA + 0X04)
#define GPIOA_IDR *(volatile uint32_t *)(GPIO_PORTA + 0x08)
#define GPIOA_ODR *(volatile uint32_t *)(GPIO_PORTA + 0x0C)

void GPIO_Init (void);
void GPIO_Delay(uint32_t nCount);

uint32_t GPIO_GetPressureVal(void);
void GPIO_Set_Alarm_Actuator(uint32_t i);


#endif /* GPIO_H_*/