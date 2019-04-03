#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>

GPIO_InitTypeDef potentiometer_gpio_handle;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

GPIO_InitTypeDef motor_control_gpio_handle;

TIM_HandleTypeDef motor_pwm_timer_handle;
TIM_OC_InitTypeDef motor_PWM_sConfig;

UART_HandleTypeDef uart_handle;

volatile char buffer;

static void Error_Handler(void);
static void SystemClock_Config(void);

volatile int adc_val;

typedef enum {
    on, off
} input_t;

volatile int index_counter = 0;
volatile char single_char;
volatile char one_line[6];
volatile input_t INPUT = on;
volatile char buffer;

void init_potentiometer_handle()
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    potentiometer_gpio_handle.Mode = GPIO_MODE_ANALOG;
    potentiometer_gpio_handle.Pin = GPIO_PIN_0;
    potentiometer_gpio_handle.Speed = GPIO_SPEED_FAST;
    potentiometer_gpio_handle.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &potentiometer_gpio_handle);

    __HAL_RCC_ADC3_CLK_ENABLE();
    adc_handle.Instance = ADC3;
    adc_handle.Init.Resolution = ADC_RESOLUTION_6B;
    HAL_ADC_Init(&adc_handle);

    adc_channel_config.Channel = ADC_CHANNEL_0;
    adc_channel_config.SamplingTime = ADC_SAMPLETIME_56CYCLES;
    HAL_ADC_ConfigChannel(&adc_handle, &adc_channel_config);
}

void init_motor_control_gpio_handle() {
    __HAL_RCC_GPIOB_CLK_ENABLE();
    motor_control_gpio_handle.Pin = GPIO_PIN_4;
    motor_control_gpio_handle.Mode = GPIO_MODE_AF_PP;
    motor_control_gpio_handle.Pull = GPIO_NOPULL;
    motor_control_gpio_handle.Speed = GPIO_SPEED_HIGH;
    motor_control_gpio_handle.Alternate = GPIO_AF2_TIM3;
    HAL_GPIO_Init(GPIOB, &motor_control_gpio_handle);
}

void init_motor_control_PWM_timer() {
    __HAL_RCC_TIM3_CLK_ENABLE();
    HAL_TIM_Base_DeInit(&motor_pwm_timer_handle);
    motor_pwm_timer_handle.Instance = TIM3;
    motor_pwm_timer_handle.Init.Prescaler = 108 - 1;
    motor_pwm_timer_handle.Init.Period = 100 - 1;
    motor_pwm_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    motor_pwm_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
    HAL_TIM_PWM_Init(&motor_pwm_timer_handle);

    motor_PWM_sConfig.Pulse = 0;
    motor_PWM_sConfig.OCMode = TIM_OCMODE_PWM1;
    motor_PWM_sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
    motor_PWM_sConfig.OCFastMode = TIM_OCFAST_ENABLE;
    HAL_TIM_PWM_ConfigChannel(&motor_pwm_timer_handle, &motor_PWM_sConfig, TIM_CHANNEL_1);
}

void init_uart()
{
    // UART receive is not finished yet!
    __HAL_RCC_USART1_CLK_ENABLE();
    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);
    HAL_NVIC_SetPriority(USART1_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(USART1_IRQn);
}


int main()
{
    HAL_Init();
    SystemClock_Config();
    init_motor_control_gpio_handle();
    init_motor_control_PWM_timer();
    HAL_TIM_PWM_Start(&motor_pwm_timer_handle, TIM_CHANNEL_1);
    init_potentiometer_handle();
    init_uart();
    HAL_UART_Receive_IT(&uart_handle, &single_char, 1);
    while (1) {

        if (INPUT == on) {
            HAL_ADC_Start(&adc_handle);
            if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK) {
                adc_val = (HAL_ADC_GetValue(&adc_handle));
                __HAL_TIM_SET_COMPARE(&motor_pwm_timer_handle, TIM_CHANNEL_1, adc_val + 14);
            }
        }
    }
}

void USART1_IRQHandler()
{
    HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *husart)
{
    if(husart->Instance == uart_handle.Instance){
        if (single_char != '\n' && index_counter < sizeof(one_line) - 1) {
            one_line[index_counter] = single_char;
            index_counter++;
        }  else if (INPUT == off) {
            while (HAL_UART_Receive(&uart_handle, (uint8_t *) &single_char, 1,
                                    HAL_MAX_DELAY) == HAL_OK) {
                if (single_char != '\n' && index_counter < sizeof(one_line) - 1) {
                    one_line[index_counter] = single_char;
                    index_counter++;
                } else {
                    one_line[index_counter] = '\0';
                    if (strcmp(one_line, "STOP") == 0) {
                        HAL_ADC_Start(&adc_handle);
                    } else if (strcmp(one_line, "START") == 0){
                        HAL_ADC_Start(&adc_handle);
                    }
                }
            }
        }
        HAL_UART_Receive_IT(&uart_handle, &single_char, 1);
        INPUT = on;
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