#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef user_button_gpio_handle;
UART_HandleTypeDef uart_handle;
TIM_HandleTypeDef LED_timer_handle;
TIM_HandleTypeDef period_timer_handle;

typedef enum {
	OPEN, SECURING, SECURED, OPENING
} system_state_t;

volatile system_state_t STATE = OPEN;
volatile u_int8_t counter = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

void init_user_button_gpio()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();
	user_button_gpio_handle.Pin = GPIO_PIN_11;
	user_button_gpio_handle.Pull = GPIO_NOPULL;
	user_button_gpio_handle.Speed = GPIO_SPEED_FAST;
	user_button_gpio_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &user_button_gpio_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
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
	uart_handle.Init.Mode = UART_MODE_TX;
	BSP_COM_Init(COM1, &uart_handle);
}

void init_LED_timer() {
	__HAL_RCC_TIM2_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&LED_timer_handle);
	LED_timer_handle.Instance = TIM2;
	LED_timer_handle.Init.Prescaler = 54000 - 1;
	LED_timer_handle.Init.Period = 1000 - 1;
	LED_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	LED_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&LED_timer_handle);
	HAL_NVIC_SetPriority(TIM2_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

void init_period_timer() {
	__HAL_RCC_TIM3_CLK_ENABLE()
	;
	HAL_TIM_Base_DeInit(&period_timer_handle);
	period_timer_handle.Instance = TIM3;
	period_timer_handle.Init.Prescaler = 54000 - 1;
	period_timer_handle.Init.Period = 2000 - 1;
	period_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	period_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&period_timer_handle);
	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

int main() {
	HAL_Init();
	SystemClock_Config();
	BSP_LED_Init(LED_GREEN);
	init_user_button_gpio();
	init_uart();
	init_LED_timer();
	init_period_timer();
	HAL_TIM_Base_Start_IT(&LED_timer_handle);
	printf("Entered in OPEN state /click to enter SECURING state/\n");
	while (1) {
	}
	return 0;
}
void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button_gpio_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == user_button_gpio_handle.Pin) {
		if (STATE == OPEN){
			STATE = SECURING;
			printf("Entered in SECURING state /5 seconds until SECURED state/\n");
			HAL_TIM_Base_Start_IT(&period_timer_handle);
		} else if (STATE == SECURED) {
			STATE = OPENING;
			printf("Entered in OPENING state /6 seconds until OPEN state/\n");
			HAL_TIM_Base_Start_IT(&period_timer_handle);
		}
	}
}

void TIM2_IRQHandler() {
	HAL_TIM_IRQHandler(&LED_timer_handle);
}

void TIM3_IRQHandler() {
	HAL_TIM_IRQHandler(&period_timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	if (htim->Instance == LED_timer_handle.Instance) {
		if (STATE == OPEN && counter == 1) {
			BSP_LED_Toggle(LED_GREEN);
			counter = 0;
		} else if (STATE == OPEN) {
			counter++; }
		else if (STATE == SECURING || STATE == OPENING){
			BSP_LED_Toggle(LED_GREEN);
		} else if(STATE == SECURED){
			BSP_LED_Off(LED_GREEN);
		}
	} else if (htim->Instance == period_timer_handle.Instance) {
		if (STATE == SECURING && counter == 5) {
			counter = 0;
			STATE = SECURED;
			HAL_TIM_Base_Stop_IT(&period_timer_handle);
			printf("Entered in SECURED state /click to enter OPENING state/\n");
		} else if (STATE == SECURING) {
			counter++; }
		 else if (STATE == OPENING && counter == 6) {
			 counter = 0;
			STATE = OPEN;
			printf("Entered in OPEN state /click to enter SECURING state/\n");
		 } else if (STATE == OPENING) {
			 counter++;}
	}
}

UART_PUTCHAR {
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct =
	{ 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct =
	{ 0 };

	__HAL_RCC_PWR_CLK_ENABLE();
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

	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
