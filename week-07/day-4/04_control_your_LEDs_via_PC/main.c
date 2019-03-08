#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

GPIO_InitTypeDef LEDS;

UART_HandleTypeDef UartHandle;

int main(void) {
	HAL_Init();

	/* enable GPIO clock */
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	LEDS.Pin = GPIO_PIN_9 | GPIO_PIN_10;
	LEDS.Mode = GPIO_MODE_OUTPUT_PP;
	LEDS.Pull = GPIO_NOPULL;
	LEDS.Speed = GPIO_SPEED_HIGH;

	/* configure GPIO for UART transmit line */
	GPIOTxConfig.Pin = GPIO_PIN_9;
	GPIOTxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIOTxConfig.Speed = GPIO_SPEED_FAST;
	GPIOTxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOA, &GPIOTxConfig);
	HAL_GPIO_Init(GPIOF, &LEDS);

	/* configure GPIO for UART receive line */
	GPIORxConfig.Pin = GPIO_PIN_7;
	GPIORxConfig.Mode = GPIO_MODE_AF_PP;
	GPIOTxConfig.Pull = GPIO_NOPULL;
	GPIORxConfig.Speed = GPIO_SPEED_FAST;
	GPIORxConfig.Alternate = GPIO_AF7_USART1;

	HAL_GPIO_Init(GPIOB, &GPIORxConfig);

	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE()
	;

	/* defining the UART configuration structure */
	UartHandle.Instance = USART1;
	UartHandle.Init.BaudRate = 115200;
	UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
	UartHandle.Init.StopBits = UART_STOPBITS_1;
	UartHandle.Init.Parity = UART_PARITY_NONE;
	UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	UartHandle.Init.Mode = UART_MODE_TX_RX;

	HAL_UART_Init(&UartHandle);
	HAL_GPIO_Init(GPIOF, &LEDS);

	uint8_t single_char;
	uint8_t one_line[100];
	int index_counter = 0;

	while (1) {
		while (HAL_UART_Receive(&UartHandle, (uint8_t*) &single_char, 1,
				HAL_MAX_DELAY) == HAL_OK) {
			if (single_char != '\n' && index_counter < sizeof(one_line) - 1) {
				one_line[index_counter] = single_char;
				index_counter++;
			} else {
				one_line[index_counter] = '\0';
				if (strcmp(one_line, "ON") == 0) {
			        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
				} else if (strcmp(one_line, "OFF") == 0) {
			        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				}


				//additional discoshit
				else if (strcmp(one_line, "DISCO") == 0) {
					for (int i = 0; i < 15; i++) {
				        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				        HAL_Delay(50);
				        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				        HAL_Delay(50);
				        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
				        HAL_Delay(50);
				        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
				        HAL_Delay(50);
					}
				}



				else {
					//HAL_UART_Transmit(&UartHandle, (uint8_t*) one_line, strlen(one_line), 0xFFFF);
					for (int i = 0; i < 3; i++) {
				        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
				        HAL_Delay(100);
				        HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
				        HAL_Delay(100);
					}
				}
				index_counter = 0;
			}
		}
	}
}
