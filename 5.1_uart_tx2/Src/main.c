#include "stm32f4xx.h"                  // Device header

void USART_write(int ch);
void USART2_Init(void);
void delay(int delayms);
int main(){

USART2_Init();
while(1){
USART_write('!');//print !
USART_write('\r');USART_write('\n'); //new line and return cursor to start of the line
delay(10);
}
}

void USART2_Init(void){
RCC->APB1ENR|=RCC_APB1ENR_USART2EN;
RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
GPIOA->AFR[0]=0x0700;
GPIOA->MODER|=(1<<5);//set bit5
GPIOA->MODER&=~(1<<4);//reset bit4
USART2->BRR  = 0x0681;    //9600 @16MHz
USART2->CR1  |=0x2008; // enable tx

}

void USART_write(int ch){
while(!(USART2->SR&0x0080)){
}
USART2->DR=(ch);

}

void delay(int delayms){
int i;
	for(; delayms>0;delayms--){
	for(i=0;i<3192;i++);
	}
}
