#include "stm32f4xx.h"





#define GPIOAEN      (1U<<0)
#define PIN5         (1U<<5)
#define LED_PIN       PIN5

int main(void)
{
	RCC->AHB1ENR |=GPIOAEN;

	GPIOA->MODER |=(1U<<10);//SET BIT 10 TO 1
	GPIOA->MODER &=~(1U<<11);//SET BIT 11 TO 0 BY INVERT IT

	while(1)
	{
		GPIOA->ODR ^=LED_PIN;//toggle the led.Toggle operator is ^
		for(int i=0;i<100000;i++){}
	}

}
