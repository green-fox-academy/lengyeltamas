#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef UartHandle;
GPIO_InitTypeDef gpio_adc_pin;
GPIO_InitTypeDef PA15_LED_config;
GPIO_InitTypeDef user_button_gpio_handle;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;
TIM_HandleTypeDef PWM_timer_handle;
TIM_OC_InitTypeDef sConfig;
TIM_HandleTypeDef frequency_timer_handle;

typedef enum {
	led_flashing,
	freq_set_mode,
	brightness_set_mode
} system_state_t;

volatile system_state_t STATE = led_flashing;
volatile uint8_t brightness = 100;
volatile float frequency = 3;
volatile uint8_t counter = 20;
volatile uint8_t led_on_off = 0;

static void Error_Handler(void);
static void SystemClock_Config(void);

int adc_val;

void init_user_button_gpio()
{
__HAL_RCC_GPIOI_CLK_ENABLE();
user_button_gpio_handle.Pin = GPIO_PIN_11;
user_button_gpio_handle.Pull = GPIO_NOPULL;
user_button_gpio_handle.Speed = GPIO_SPEED_FAST;
user_button_gpio_handle.Mode = GPIO_MODE_IT_RISING;
HAL_GPIO_Init(GPIOI, &user_button_gpio_handle);
HAL_NVIC_SetPriority(EXTI15_10_IRQn, 1, 0);
HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void init_LED_gpio()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    PA15_LED_config.Pin = GPIO_PIN_15;
    PA15_LED_config.Mode = GPIO_MODE_AF_PP;
    PA15_LED_config.Pull = GPIO_NOPULL;
    PA15_LED_config.Speed = GPIO_SPEED_HIGH;
    PA15_LED_config.Alternate = GPIO_AF1_TIM2;
    HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_PWM_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&PWM_timer_handle);
	PWM_timer_handle.Instance = TIM2;
	PWM_timer_handle.Init.Prescaler = 108 - 1;
	PWM_timer_handle.Init.Period = 100 - 1;
	PWM_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	PWM_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_PWM_Init(&PWM_timer_handle);

    sConfig.Pulse = 100;
    sConfig.OCMode = TIM_OCMODE_PWM1;
    sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    sConfig.OCFastMode = TIM_OCFAST_ENABLE;
    HAL_TIM_PWM_ConfigChannel(&PWM_timer_handle, &sConfig, TIM_CHANNEL_1);
}

void init_frequency_timer()
{
	__HAL_RCC_TIM3_CLK_ENABLE();
	HAL_TIM_Base_DeInit(&frequency_timer_handle);
	frequency_timer_handle.Instance = TIM3;
	frequency_timer_handle.Init.Prescaler = 54000 - 1;
	frequency_timer_handle.Init.Period = 100 - 1;
	frequency_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	frequency_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
	HAL_TIM_Base_Init(&frequency_timer_handle);
	HAL_NVIC_SetPriority(TIM3_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    __HAL_RCC_USART1_CLK_ENABLE();
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    BSP_COM_Init(COM1, &UartHandle);

    __HAL_RCC_GPIOA_CLK_ENABLE();
    gpio_adc_pin.Mode = GPIO_MODE_ANALOG;
    gpio_adc_pin.Pin = GPIO_PIN_0;
    gpio_adc_pin.Speed = GPIO_SPEED_FAST;
    gpio_adc_pin.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &gpio_adc_pin);

    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    HAL_ADC_Init(&adc_handle);

    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);

    init_user_button_gpio();
    init_LED_gpio();
    init_PWM_timer();
    init_frequency_timer();
    HAL_TIM_PWM_Start(&PWM_timer_handle, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_IT(&frequency_timer_handle);
    // NOT FINISHED YET!
    while (1) {
        HAL_ADC_Start(&adc_handle);
        	if (STATE == brightness_set_mode) {
        		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
        		adc_val = ((HAL_ADC_GetValue(&adc_handle) / 82 ));
        		}
        	} else if (STATE == freq_set_mode) {
        		if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
        		frequency = ((HAL_ADC_GetValue(&adc_handle)) / 215) + 1;
        		}
        	}
        }
    }


void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(user_button_gpio_handle.Pin);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if (GPIO_Pin == user_button_gpio_handle.Pin) {
		if (STATE == led_flashing){
			STATE = brightness_set_mode;
		} else if (STATE == brightness_set_mode) {
			STATE = freq_set_mode;
		}  else if (STATE == freq_set_mode) {
			STATE = led_flashing;
		}
	}
}

void TIM3_IRQHandler()
{
	HAL_TIM_IRQHandler(&frequency_timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == frequency_timer_handle.Instance) {
		if (counter >= frequency){
			if (led_on_off == 0){
				__HAL_TIM_SET_COMPARE(&PWM_timer_handle, TIM_CHANNEL_1, adc_val);
				led_on_off = 1;
			} else if (led_on_off == 1){
				__HAL_TIM_SET_COMPARE(&PWM_timer_handle, TIM_CHANNEL_1, 0);
				led_on_off = 0;
			}
			counter = 0;
		} else {
			counter++;
		}
	}
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&UartHandle, (uint8_t*) &ch, 1, 0xFFFF);
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
