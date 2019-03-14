#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>
#define UART_PUTCHAR int __io_putchar(int ch)

TIM_HandleTypeDef timer_handle;
GPIO_InitTypeDef led_handle;
UART_HandleTypeDef uart_handle;
GPIO_InitTypeDef GPIOTxConfig;
GPIO_InitTypeDef GPIORxConfig;

typedef enum {
	on, off, flash
} input_t;

volatile int index_counter = 0;
volatile char single_char;
volatile char one_line[6];
volatile input_t INPUT = flash;
volatile char buffer;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_timer() {
	SystemClock_Config();
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&timer_handle);
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 54000 - 1;
	timer_handle.Init.Period = 1000 - 1;
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&timer_handle);
	HAL_NVIC_SetPriority(TIM2_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_gpio_led() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	led_handle.Pin = GPIO_PIN_10;
	led_handle.Pull = GPIO_NOPULL;
	led_handle.Speed = GPIO_SPEED_FAST;
	led_handle.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOF, &led_handle);
}

void init_uart() {
	__HAL_RCC_USART1_CLK_ENABLE()
	;
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
	HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(USART1_IRQn);
}

int main() {
	HAL_Init();
	init_timer();
	init_uart();
	HAL_TIM_Base_Start_IT(&timer_handle);
	HAL_UART_Receive_IT(&uart_handle, &single_char, 1);
	init_gpio_led();
	int first_run = 1;
	while (1) {
		if (INPUT == on) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
			first_run = 0;
			HAL_TIM_Base_Stop_IT(&timer_handle);
		} else if (INPUT == off) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
			first_run = 0;
			HAL_TIM_Base_Stop_IT(&timer_handle);
		} else if (INPUT == flash) {
			if (!first_run) {
				HAL_TIM_Base_Start_IT(&timer_handle);
				first_run = 1;
			}
		}
	}
	return 0;
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == timer_handle.Instance) {
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	}
}

void USART1_IRQHandler() {
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *husart) {
	if (husart->Instance == uart_handle.Instance) {
		if (single_char != '\n' && index_counter < sizeof(one_line) - 1) {
			one_line[index_counter] = single_char;
			index_counter++;
		} else {
			one_line[index_counter] = '\0';
			index_counter = 0;
			if (strcmp(one_line, "flash") == 0) {
				INPUT = flash;
			} else if (strcmp(one_line, "on") == 0) {
				INPUT = on;
			} else if (strcmp(one_line, "off") == 0) {
				INPUT = off;
			}
		}
		HAL_UART_Receive_IT(&uart_handle, &single_char, 1);
	}
}

static void SystemClock_Config(void) {
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
			| RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}

static void Error_Handler(void) {
}

UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
