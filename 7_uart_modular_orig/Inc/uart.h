/*
 * uart.h
 *
 *  Created on: 2023年1月3日
 *      Author: Howard
 */

#ifndef UART_H_
#define UART_H_
#include <stdint.h>
#include "stm32f4xx.h"

void uar2_tx_init(void);
void uart2_write(int ch);


#endif /* UART_H_ */
