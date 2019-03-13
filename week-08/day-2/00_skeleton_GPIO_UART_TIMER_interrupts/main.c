#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

GPIO_InitTypeDef gpio_handle;

UART_HandleTypeDef uart_handle;

TIM_HandleTypeDef timer_handle;

#define UART_PUTCHAR int __io_putchar(int ch)
														// preprocessor for set the printf
														// (which is basically int __io_putchar(int ch) inside itself)
														// check below

static void Error_Handler(void);
														// error handler not implemented yet
static void SystemClock_Config(void);
														// System clock is a must have for the timer initialization
volatile char buffer;

void init_gpio()
														// Initializing GPIO:
{
														// Enable clock for GPIO I port
__HAL_RCC_GPIOI_CLK_ENABLE();

														// Configure gpio_handle struct
gpio_handle.Pin = GPIO_PIN_11;
														// Set I port's 11th pin (board blue button)
gpio_handle.Pull = GPIO_NOPULL;
														// no pull-up resistor
gpio_handle.Speed = GPIO_SPEED_FAST;

gpio_handle.Mode = GPIO_MODE_IT_RISING;
														// IT = interrupt for the rising edge
														// don't forget to set .Mode to GPIO_MODE_OUTPUT_PP
														// if you are using this skeleton for initializing a GPIO LED!

														// gpio_handle.Alternate to be set only
														// when you use the pin for output (PWM)
														// You also need to modify the .Mode this case!

HAL_GPIO_Init(GPIOI, &gpio_handle);
														// Initializing GPIO I port for the gpio_handle struct

HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);
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
	HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
														// set priority for USART1, preempt priority 1, sub priority 0
	HAL_NVIC_EnableIRQ(USART1_IRQn);
														// enable interrupt for USART1
}

void init_timer()
{
	SystemClock_Config();
	__HAL_RCC_TIM2_CLK_ENABLE();
														// set the clock for the timer (TIM2)
	HAL_TIM_Base_DeInit(&timer_handle);
														// de-initialize the TIM_Base, because of safety reasons.
														// if it's already initialized, this step de-initialize it
	timer_handle.Instance = TIM2;
														// set structure for the TIM2 timer
	timer_handle.Init.Prescaler = 54000 - 1;			// 1 / (clock value / prescaler value) = prescaler time unit
														// 1 / (108000000 / 54000) = 0,0005 = 0,5 ms

	timer_handle.Init.Period = 12000 - 1;				// period time = prescaler time unit * period value
														// period time = 0,5 ms (0,0005 s) * (12000 - 1) = 6 s

	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);
														// initialize the timer

	HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main ()
{
			HAL_Init();
														// at first step we have to initialize the HAL
			BSP_LED_Init(LED_GREEN);
														// initializing the board green led with BSP
			init_gpio();
														// running GPIO instance initialization
			init_uart();
														// running the UART initialization
			init_timer();
														// running the TIMER initialization, in the functions first step
														// you run the SystemClock_Config static void function
			HAL_TIM_Base_Start_IT(&timer_handle);
														// this code line starts the timer in interrupt mode (IT)
														// it's parameter is a pointer to the timer struct
														// you set with the init_timer function

			HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
														// this code line starts the UART communication in interrupt mode
														// it's first parameter is a pointer to the UART struct
														// you set with the init_uart function
														// second parameter is a pointer to the variable you'll store the received input
														// third parameter is the length of the previous variable
			while (1) {
			}
			return 0;
}

	/*GPIO handler and callback*/


void EXTI15_10_IRQHandler()
														// the name of the function must come from the startup/startup_stm32f746xx.s file,
{
	HAL_GPIO_EXTI_IRQHandler(gpio_handle.Pin);
														// set PIN from the EXTI15_10 range, for the Interrupt handler
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
														// the name of the callback function comes from the Handler function's HAL_GPIO_EXTI_IRQHandler line's function
{
	if (GPIO_Pin == gpio_handle.Pin) {
														// Check if the funnction's input parameter PIN is the one we defined in the struct,
			//BSP_LED_Toggle(LED_GREEN);
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
	if(husart->Instance == uart_handle.Instance){
														// check if the parameter UART struct is the USART1
		//BSP_LED_Toggle(LED_GREEN);

		HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
	}
}


	/*TIMER handler and callback*/


void TIM2_IRQHandler()
														// the name of the function must come from the startup/startup_stm32f746xx.s file
{
	HAL_TIM_IRQHandler(&timer_handle);
														// set timer_handle structure for the TIM2 handler
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == timer_handle.Instance) {

		BSP_LED_Toggle(LED_GREEN);
	}
}

UART_PUTCHAR
														// after this point the UART_PUTCHAR is equal
														// with the int __io_putchar(int ch) (see it above)
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
	return ch;
														// after this code line the bulit in printf command is equal with the
														// HAL_UART_Transmit command
}

static void Error_Handler(void)
														// error handling is not implemented yet
{
}

static void SystemClock_Config(void)
														// clock configuration for the timer,
														// it's called in the init_timer function's first line
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE();
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
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

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
