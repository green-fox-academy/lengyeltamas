#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef USER_BUTTON_gpio_handle;
GPIO_InitTypeDef EXTERNAL_LED_gpio_handle;
TIM_HandleTypeDef LED_timer_handle;
TIM_OC_InitTypeDef LED_sConfig;
TIM_HandleTypeDef period_timer_handle;
UART_HandleTypeDef uart_handle;

volatile uint32_t timer_value = 0;
volatile uint32_t starting_tick = 0;
volatile uint32_t energy_value = 0;

volatile uint8_t button_callback_counter = 1;

typedef enum {
	SET_TIMER,
	SET_ENERGY,
	RUNNING,
	STOPPED
} state_t;

typedef enum {
	LOW,
	MEDIUM,
	HIGH,
	MAXIMUM
} energy_level_t;

volatile state_t STATE = STOPPED;
volatile energy_level_t ENERGY;
static void Error_Handler(void);
static void SystemClock_Config();
void init_USER_BUTTON_gpio();
void init_EXTERNAL_LED_gpio();
void init_uart();
void init_LED_PWM_timer();

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_USER_BUTTON_gpio();
	init_EXTERNAL_LED_gpio();
	init_uart();
	init_LED_PWM_timer();
	HAL_TIM_PWM_Start(&LED_timer_handle, TIM_CHANNEL_1);

	while(1)
	{

	}
}

void init_USER_BUTTON_gpio()
{
	__HAL_RCC_GPIOI_CLK_ENABLE();
	USER_BUTTON_gpio_handle.Pin = GPIO_PIN_11;
	USER_BUTTON_gpio_handle.Pull = GPIO_NOPULL;
	USER_BUTTON_gpio_handle.Speed = GPIO_SPEED_FAST;
	USER_BUTTON_gpio_handle.Mode = GPIO_MODE_IT_RISING_FALLING;
	HAL_GPIO_Init(GPIOI, &USER_BUTTON_gpio_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_EXTERNAL_LED_gpio()
{
	__HAL_RCC_GPIOA_CLK_ENABLE();
	EXTERNAL_LED_gpio_handle.Pin = GPIO_PIN_15;
	EXTERNAL_LED_gpio_handle.Pull = GPIO_NOPULL;
	EXTERNAL_LED_gpio_handle.Speed = GPIO_SPEED_FAST;
	EXTERNAL_LED_gpio_handle.Mode = GPIO_MODE_AF_OD;
	EXTERNAL_LED_gpio_handle.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOA, &EXTERNAL_LED_gpio_handle);
}

void init_LED_PWM_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&LED_timer_handle);
	LED_timer_handle.Instance = TIM2;
	LED_timer_handle.Init.Prescaler = 108 - 1;
	LED_timer_handle.Init.Period = 100 - 1;
	LED_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	LED_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&LED_timer_handle);

	LED_sConfig.Pulse = 0;
	LED_sConfig.OCMode = TIM_OCMODE_PWM1;
	LED_sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	LED_sConfig.OCFastMode = TIM_OCFAST_ENABLE;
	HAL_TIM_PWM_ConfigChannel(&LED_timer_handle, &LED_sConfig, TIM_CHANNEL_1);
}

void init_uart()
{
	__HAL_RCC_USART1_CLK_ENABLE();
	uart_handle.Instance = USART1;
	uart_handle.Init.BaudRate = 115200;
	uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
	uart_handle.Init.StopBits = UART_STOPBITS_1;
	uart_handle.Init.Parity = UART_PARITY_NONE;
	uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart_handle.Init.Mode = UART_MODE_TX_RX;
	BSP_COM_Init(COM1, &uart_handle);
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(USER_BUTTON_gpio_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == USER_BUTTON_gpio_handle.Pin) {
		if (STATE == STOPPED && (button_callback_counter % 2) == 1){
			starting_tick = HAL_GetTick();
			button_callback_counter++;
		} else if (STATE == STOPPED && (button_callback_counter % 2) == 0) {
			timer_value = HAL_GetTick() - starting_tick;
			STATE = SET_TIMER;
			button_callback_counter++;
		} else if (STATE == SET_TIMER && (button_callback_counter % 2) == 1) {
			starting_tick = HAL_GetTick();
			button_callback_counter++;
		} else if (STATE == SET_TIMER && (button_callback_counter % 2) == 0) {
			energy_value = HAL_GetTick() - starting_tick;
			STATE = SET_ENERGY;
			button_callback_counter++;
		} else if (STATE == SET_ENERGY) {
			if (energy_value ) {

			}
		}

		}
}




UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
	return ch;
}


static void Error_Handler(void)
{
}

static void SystemClock_Config()
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
