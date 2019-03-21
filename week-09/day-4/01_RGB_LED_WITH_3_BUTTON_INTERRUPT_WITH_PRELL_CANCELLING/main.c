#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

GPIO_InitTypeDef RGB_LED_handle;
GPIO_InitTypeDef gpio_RED_button_handle;
GPIO_InitTypeDef gpio_GREEN_button_handle;
GPIO_InitTypeDef gpio_BLUE_button_handle;

volatile uint32_t previous_tick = 0;

void init_RGB_LED_gpio() {
	__HAL_RCC_GPIOF_CLK_ENABLE();
	RGB_LED_handle.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8;
	RGB_LED_handle.Pull = GPIO_NOPULL;
	RGB_LED_handle.Speed = GPIO_SPEED_FAST;
	RGB_LED_handle.Mode = GPIO_MODE_OUTPUT_PP;
	HAL_GPIO_Init(GPIOF, &RGB_LED_handle);
}

void init_RED_BUTTON_gpio()
{
__HAL_RCC_GPIOB_CLK_ENABLE();
gpio_RED_button_handle.Pin = GPIO_PIN_14;
gpio_RED_button_handle.Pull = GPIO_NOPULL;
gpio_RED_button_handle.Speed = GPIO_SPEED_FAST;
gpio_RED_button_handle.Mode = GPIO_MODE_IT_RISING;
HAL_GPIO_Init(GPIOB, &gpio_RED_button_handle);
HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_GREEN_BUTTON_gpio()
{
__HAL_RCC_GPIOB_CLK_ENABLE();
gpio_GREEN_button_handle.Pin = GPIO_PIN_15;
gpio_GREEN_button_handle.Pull = GPIO_NOPULL;
gpio_GREEN_button_handle.Speed = GPIO_SPEED_FAST;
gpio_GREEN_button_handle.Mode = GPIO_MODE_IT_RISING;
HAL_GPIO_Init(GPIOB, &gpio_GREEN_button_handle);
HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_BLUE_BUTTON_gpio()
{
__HAL_RCC_GPIOI_CLK_ENABLE();
gpio_BLUE_button_handle.Pin = GPIO_PIN_11;
gpio_BLUE_button_handle.Pull = GPIO_NOPULL;
gpio_BLUE_button_handle.Speed = GPIO_SPEED_FAST;
gpio_BLUE_button_handle.Mode = GPIO_MODE_IT_RISING;
HAL_GPIO_Init(GPIOI, &gpio_BLUE_button_handle);
HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();
	init_RGB_LED_gpio();
	init_RED_BUTTON_gpio();
	init_GREEN_BUTTON_gpio();
	init_BLUE_BUTTON_gpio();

	while (1) {
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(gpio_RED_button_handle.Pin);
	HAL_GPIO_EXTI_IRQHandler(gpio_GREEN_button_handle.Pin);
	HAL_GPIO_EXTI_IRQHandler(gpio_BLUE_button_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == gpio_RED_button_handle.Pin) {
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_SET) {
			uint32_t actual_tick = HAL_GetTick();
			uint32_t period_time = actual_tick - previous_tick;

			if (period_time < actual_tick && period_time > 250){
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
			}
			previous_tick = actual_tick;
		}
										// here you can set different callback cases for different ports with else if's
	} else if (GPIO_Pin == gpio_GREEN_button_handle.Pin) {
		if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15) == GPIO_PIN_SET) {
			uint32_t actual_tick = HAL_GetTick();
			uint32_t period_time = actual_tick - previous_tick;
			if (period_time < actual_tick && period_time > 250){
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_8);
			}
			previous_tick = actual_tick;
		}
	} else if (GPIO_Pin == gpio_BLUE_button_handle.Pin) {

		if (HAL_GPIO_ReadPin(GPIOI, GPIO_PIN_11) == GPIO_PIN_SET) {
			uint32_t actual_tick = HAL_GetTick();
			uint32_t period_time = actual_tick - previous_tick;
			if (period_time < actual_tick && period_time > 250){
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
			}
			previous_tick = actual_tick;
		}
	}
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
