#include "stm32f4xx.h"





#define GPIOAEN      (1U<<0)
#define GPIOCEN		 (1U<<2)//SHIFT 1 TO 2

#define PIN5         (1U<<5)
#define PIN13		 (1U<<13)

#define LED_PIN       PIN5
#define BTN_PIN		  PIN13

int main(void)
{
	/*Enable clock access to GPIOA and GPIOC*/
	RCC->AHB1ENR |=GPIOAEN;
	RCC->AHB1ENR |=GPIOCEN;

	GPIOA->MODER |=(1U<<10);//SET BIT 10 TO 1
	GPIOA->MODER &=~(1U<<11);//SET BIT 11 TO 0 BY INVERT IT

	/*set PC13 as input*/
	GPIOC->MODER &=~ (1U<<26);
	GPIOC->MODER &=~ (1U<<27);

	while(1)
	{
		/*check if the btn is press*/
		if(GPIOC->IDR & BTN_PIN)
		{
			/*turn on led*/
			GPIOA->BSRR = LED_PIN;


		}else{
			//turn off led
			GPIOA->BSRR = (1U<<21);

		}

	}

}
