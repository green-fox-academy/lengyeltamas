#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

GPIO_InitTypeDef user_button_handle;

UART_HandleTypeDef uart_handle;

volatile char buffer;

void init_user_button() {
													// Initializing user push button:

													// Step 1, enable clock for GPIO I port
	__HAL_RCC_GPIOI_CLK_ENABLE();

													// Configure user_button_handle struct

	user_button_handle.Pin = GPIO_PIN_11;
													// Set I port's 11th pin (board blue button)
	user_button_handle.Pull = GPIO_NOPULL;
													// no pull-up resistor
	user_button_handle.Speed = GPIO_SPEED_FAST;

	user_button_handle.Mode = GPIO_MODE_IT_RISING;
													// IT = interrupt for the rising edge
													// user_button_handle.Alternate to be set only when you use the pin for output (eg. PWM)
													// You also need to modify the .Mode this case!

	HAL_GPIO_Init(GPIOI, &user_button_handle);
													// Initializing GPIO I port for the user_button_handle struct

	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 4, 0);
													// Set priority for the EXTI lines 15:10, preempt priority 4, sub priority 0

	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
													// Enable interrupt for EXTI lines 15:10
}




void init_uart()
													// Initializing UART communication
{
	__HAL_RCC_USART1_CLK_ENABLE();
													// Enable clock for the USART1
	uart_handle.Instance = USART1;
													// set USART1 register
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
													// set 8 bit word length
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;

	BSP_COM_Init(COM1, &uart_handle);
													// initializing COM1 line for USB UART emulation line (Hercules)
	HAL_NVIC_SetPriority(USART1_IRQn, 1, 0);
													// set priority for USART1, preempt priority 1, sub priority 0
	HAL_NVIC_EnableIRQ(USART1_IRQn);
													// enable interrupt for USART1
}



int main ()
{
	HAL_Init();

		BSP_LED_Init(LED_GREEN);
		init_user_button();
		init_uart();

		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

		while (1) {
		}

		return 0;
}

/*GPIO handler and callback*/


void EXTI15_10_IRQHandler()
													// the name of the function must come from the startup/startup_stm32f746xx.s file,
{
	HAL_GPIO_EXTI_IRQHandler(user_button_handle.Pin);
													// set PIN from the EXTI15_10 range, for the Interrupt handler
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
													// the name of the callback function comes from the Handler function's HAL_GPIO_EXTI_IRQHandler line's function
{
	if (GPIO_Pin == user_button_handle.Pin) {
													// Check if the funnction's input parameter PIN is the one we defined in the struct,
			BSP_LED_Toggle(LED_GREEN);
													// so this way, we can toggle only the the GPIO_PIN_11 from the selected EXTI15_10 (PIN 15 - 10) range
		}
}


/*UART handler and callback*/


void USART1_IRQHandler()
													// the name of the function must come from the startup/startup_stm32f746xx.s file
{
	HAL_UART_IRQHandler(&uart_handle);
													// set UART structure for the UART handler
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *husart)
{
	if(husart->Instance == USART1){
													// check if the parameter UART struct is the USART1
		BSP_LED_Toggle(LED_GREEN);

		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	}
}
