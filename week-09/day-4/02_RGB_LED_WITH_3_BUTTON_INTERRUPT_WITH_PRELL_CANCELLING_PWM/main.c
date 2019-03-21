#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

GPIO_InitTypeDef RED_LED_gpio_handle;
GPIO_InitTypeDef GREEN_LED_gpio_handle;
GPIO_InitTypeDef BLUE_LED_gpio_handle;

GPIO_InitTypeDef RED_BUTTON_gpio_handle;
GPIO_InitTypeDef GREEN_BUTTON_gpio_handle;
GPIO_InitTypeDef BLUE_BUTTON_gpio_handle;

TIM_HandleTypeDef RED_LED_timer_handle;
TIM_OC_InitTypeDef RED_LED_sConfig;

TIM_HandleTypeDef GREEN_LED_timer_handle;
TIM_OC_InitTypeDef GREEN_LED_sConfig;

TIM_HandleTypeDef BLUE_LED_timer_handle;
TIM_OC_InitTypeDef BLUE_LED_sConfig;

volatile uint32_t previous_tick = 0;
volatile uint8_t RED_LED_on_off = 0;
volatile uint8_t GREEN_LED_on_off = 0;
volatile uint8_t BLUE_LED_on_off = 0;

void init_RED_LED_gpio() {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	RED_LED_gpio_handle.Pin = GPIO_PIN_15;
	RED_LED_gpio_handle.Pull = GPIO_NOPULL;
	RED_LED_gpio_handle.Speed = GPIO_SPEED_FAST;
	RED_LED_gpio_handle.Mode = GPIO_MODE_AF_OD;
	RED_LED_gpio_handle.Alternate = GPIO_AF1_TIM2;
	HAL_GPIO_Init(GPIOA, &RED_LED_gpio_handle);
}

void init_GREEN_LED_gpio() {
	__HAL_RCC_GPIOI_CLK_ENABLE();
	GREEN_LED_gpio_handle.Pin = GPIO_PIN_0;
	GREEN_LED_gpio_handle.Pull = GPIO_NOPULL;
	GREEN_LED_gpio_handle.Speed = GPIO_SPEED_FAST;
	GREEN_LED_gpio_handle.Mode = GPIO_MODE_AF_OD;
	GREEN_LED_gpio_handle.Alternate = GPIO_AF2_TIM5;
	HAL_GPIO_Init(GPIOI, &GREEN_LED_gpio_handle);
}

void init_BLUE_LED_gpio() {
	__HAL_RCC_GPIOB_CLK_ENABLE();
	BLUE_LED_gpio_handle.Pin = GPIO_PIN_4;
	BLUE_LED_gpio_handle.Pull = GPIO_NOPULL;
	BLUE_LED_gpio_handle.Speed = GPIO_SPEED_FAST;
	BLUE_LED_gpio_handle.Mode = GPIO_MODE_AF_OD;
	BLUE_LED_gpio_handle.Alternate = GPIO_AF2_TIM3;
	HAL_GPIO_Init(GPIOB, &BLUE_LED_gpio_handle);
}

void init_RED_BUTTON_gpio() {
	__HAL_RCC_GPIOI_CLK_ENABLE();
	RED_BUTTON_gpio_handle.Pin = GPIO_PIN_2;
	RED_BUTTON_gpio_handle.Pull = GPIO_NOPULL;
	RED_BUTTON_gpio_handle.Speed = GPIO_SPEED_FAST;
	RED_BUTTON_gpio_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOI, &RED_BUTTON_gpio_handle);
	HAL_NVIC_SetPriority(EXTI2_IRQn, 1, 0);
	HAL_NVIC_EnableIRQ(EXTI2_IRQn);
}

void init_GREEN_BUTTON_gpio() {
	__HAL_RCC_GPIOA_CLK_ENABLE();
	GREEN_BUTTON_gpio_handle.Pin = GPIO_PIN_8;
	GREEN_BUTTON_gpio_handle.Pull = GPIO_NOPULL;
	GREEN_BUTTON_gpio_handle.Speed = GPIO_SPEED_FAST;
	GREEN_BUTTON_gpio_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOA, &GREEN_BUTTON_gpio_handle);
	HAL_NVIC_SetPriority(EXTI9_5_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);
}

void init_BLUE_BUTTON_gpio() {
	__HAL_RCC_GPIOB_CLK_ENABLE();
	BLUE_BUTTON_gpio_handle.Pin = GPIO_PIN_15;
	BLUE_BUTTON_gpio_handle.Pull = GPIO_NOPULL;
	BLUE_BUTTON_gpio_handle.Speed = GPIO_SPEED_FAST;
	BLUE_BUTTON_gpio_handle.Mode = GPIO_MODE_IT_RISING;
	HAL_GPIO_Init(GPIOB, &BLUE_BUTTON_gpio_handle);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 3, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_RED_LED_PWM_timer() {
	__HAL_RCC_TIM2_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&RED_LED_timer_handle);
	RED_LED_timer_handle.Instance = TIM2;
	RED_LED_timer_handle.Init.Prescaler = 108 - 1;
	RED_LED_timer_handle.Init.Period = 100 - 1;
	RED_LED_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	RED_LED_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&RED_LED_timer_handle);

	RED_LED_sConfig.Pulse = 50;
	RED_LED_sConfig.OCMode = TIM_OCMODE_PWM1;
	RED_LED_sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	RED_LED_sConfig.OCFastMode = TIM_OCFAST_ENABLE;
	HAL_TIM_PWM_ConfigChannel(&RED_LED_timer_handle, &RED_LED_sConfig, TIM_CHANNEL_1);
}

void init_GREEN_LED_PWM_timer() {
	__HAL_RCC_TIM5_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&GREEN_LED_timer_handle);
	GREEN_LED_timer_handle.Instance = TIM5;
	GREEN_LED_timer_handle.Init.Prescaler = 108 - 1;
	GREEN_LED_timer_handle.Init.Period = 100 - 1;
	GREEN_LED_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	GREEN_LED_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&GREEN_LED_timer_handle);

	GREEN_LED_sConfig.Pulse = 50;
	GREEN_LED_sConfig.OCMode = TIM_OCMODE_PWM1;
	GREEN_LED_sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	GREEN_LED_sConfig.OCFastMode = TIM_OCFAST_ENABLE;
	HAL_TIM_PWM_ConfigChannel(&GREEN_LED_timer_handle, &GREEN_LED_sConfig, TIM_CHANNEL_4);
}

void init_BLUE_LED_PWM_timer() {
	__HAL_RCC_TIM3_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&BLUE_LED_timer_handle);
	BLUE_LED_timer_handle.Instance = TIM3;
	BLUE_LED_timer_handle.Init.Prescaler = 108 - 1;
	BLUE_LED_timer_handle.Init.Period = 100 - 1;
	BLUE_LED_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	BLUE_LED_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&BLUE_LED_timer_handle);

	BLUE_LED_sConfig.Pulse = 50;
	BLUE_LED_sConfig.OCMode = TIM_OCMODE_PWM1;
	BLUE_LED_sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
	BLUE_LED_sConfig.OCFastMode = TIM_OCFAST_ENABLE;
	HAL_TIM_PWM_ConfigChannel(&BLUE_LED_timer_handle, &BLUE_LED_sConfig, TIM_CHANNEL_1);
}

int main(void) {
	HAL_Init();
	SystemClock_Config();

	init_RED_LED_gpio();
	init_GREEN_LED_gpio();
	init_BLUE_LED_gpio();

	init_RED_BUTTON_gpio();
	init_GREEN_BUTTON_gpio();
	init_BLUE_BUTTON_gpio();

	init_RED_LED_PWM_timer();
	init_GREEN_LED_PWM_timer();
	init_BLUE_LED_PWM_timer();

	HAL_TIM_PWM_Start(&RED_LED_timer_handle, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&GREEN_LED_timer_handle, TIM_CHANNEL_4);
	HAL_TIM_PWM_Start(&BLUE_LED_timer_handle, TIM_CHANNEL_1);

	while (1) {
	}
}

void EXTI2_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
}

void EXTI9_5_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_8);
}

void EXTI15_10_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_15);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	uint32_t period_time = HAL_GetTick() - previous_tick;
	if (period_time > HAL_GetTick() || period_time < 250) {
		return;
	}

	if (GPIO_Pin == RED_BUTTON_gpio_handle.Pin) {
		if (RED_LED_on_off == 0) {
			__HAL_TIM_SET_COMPARE(&RED_LED_timer_handle, TIM_CHANNEL_1, 50);
			RED_LED_on_off = 1;
		} else if (RED_LED_on_off == 1) {
			__HAL_TIM_SET_COMPARE(&RED_LED_timer_handle, TIM_CHANNEL_1, 100);
			RED_LED_on_off = 0;
		}

	} else if (GPIO_Pin == GREEN_BUTTON_gpio_handle.Pin) {
		if (GREEN_LED_on_off == 0) {
			__HAL_TIM_SET_COMPARE(&GREEN_LED_timer_handle, TIM_CHANNEL_4, 50);
			GREEN_LED_on_off = 1;
		} else if (GREEN_LED_on_off == 1) {
			__HAL_TIM_SET_COMPARE(&GREEN_LED_timer_handle, TIM_CHANNEL_4, 100);
			GREEN_LED_on_off = 0;
		}

	} else if (GPIO_Pin == BLUE_BUTTON_gpio_handle.Pin) {
		if (BLUE_LED_on_off == 0) {
			__HAL_TIM_SET_COMPARE(&BLUE_LED_timer_handle, TIM_CHANNEL_1, 100);
			BLUE_LED_on_off = 1;
		} else if (BLUE_LED_on_off == 1) {
			__HAL_TIM_SET_COMPARE(&BLUE_LED_timer_handle, TIM_CHANNEL_1, 0);
			BLUE_LED_on_off = 0;
		}
	}
	previous_tick = HAL_GetTick();
}

static void Error_Handler(void) {
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
