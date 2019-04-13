#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include <string.h>
#include <stdlib.h>
#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef potentiometer_gpio_handle;
ADC_HandleTypeDef adc_handle;
ADC_ChannelConfTypeDef adc_channel_config;

GPIO_InitTypeDef motor_control_gpio_handle;
TIM_HandleTypeDef motor_pwm_timer_handle;
TIM_OC_InitTypeDef motor_PWM_sConfig;

GPIO_InitTypeDef comparator_gpio_handle;
TIM_HandleTypeDef comparator_timer_handle;
TIM_IC_InitTypeDef comparator_ic_handle;

TIM_HandleTypeDef printf_timer_handle;

UART_HandleTypeDef uart_handle;

static void Error_Handler(void);
static void SystemClock_Config(void);
static void MPU_Config(void);
static void CPU_CACHE_Enable(void);
void PI_controller();

volatile int adc_val;
volatile int inputRPM = 0;
volatile int outputRPM = 0;
volatile int overflow = 0;
volatile int timcounter = 0;
volatile int regitimcounter = 0;
volatile int previous = 0;
volatile int steps = 0;
volatile double T = 0;
volatile int maxRPM = 5150;
volatile int minRPM = 0;
volatile float percentage;
volatile int integral = 0;
volatile int err = 0;
volatile float P = 0.05;
volatile float I = 0.01;
volatile int difference = 0;
volatile float freq = 0;
volatile float ctrl_out = 0;

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

void init_motor_control_gpio_handle()
{
  __HAL_RCC_GPIOB_CLK_ENABLE();
  motor_control_gpio_handle.Pin = GPIO_PIN_4;
  motor_control_gpio_handle.Mode = GPIO_MODE_AF_PP;
  motor_control_gpio_handle.Pull = GPIO_NOPULL;
  motor_control_gpio_handle.Speed = GPIO_SPEED_HIGH;
  motor_control_gpio_handle.Alternate = GPIO_AF2_TIM3;
  HAL_GPIO_Init(GPIOB, &motor_control_gpio_handle);
}

void init_motor_control_PWM_timer()
{
  __HAL_RCC_TIM3_CLK_ENABLE();
  HAL_TIM_Base_DeInit(&motor_pwm_timer_handle);
  motor_pwm_timer_handle.Instance = TIM3;
  motor_pwm_timer_handle.Init.Prescaler = 1;
  motor_pwm_timer_handle.Init.Period = 100;
  motor_pwm_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  motor_pwm_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_PWM_Init(&motor_pwm_timer_handle);

  motor_PWM_sConfig.Pulse = 0;
  motor_PWM_sConfig.OCMode = TIM_OCMODE_PWM1;
  motor_PWM_sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
  motor_PWM_sConfig.OCFastMode = TIM_OCFAST_ENABLE;
  HAL_TIM_PWM_ConfigChannel(&motor_pwm_timer_handle, &motor_PWM_sConfig,
  TIM_CHANNEL_1);

  HAL_TIM_Base_Start(&motor_pwm_timer_handle);
  HAL_TIM_PWM_Start(&motor_pwm_timer_handle, TIM_CHANNEL_1);
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

void init_comparator_gpio()
{
  __HAL_RCC_GPIOA_CLK_ENABLE();
  comparator_gpio_handle.Pin = GPIO_PIN_15;
  comparator_gpio_handle.Mode = GPIO_NOPULL;
  comparator_gpio_handle.Speed = GPIO_SPEED_FAST;
  comparator_gpio_handle.Mode = GPIO_MODE_AF_OD;
  comparator_gpio_handle.Alternate = GPIO_AF1_TIM2;
  HAL_GPIO_Init(GPIOA, &comparator_gpio_handle);
}

void init_comparator_timer()
{
  __HAL_RCC_TIM2_CLK_ENABLE();
  HAL_TIM_Base_DeInit(&comparator_timer_handle);
  comparator_timer_handle.Instance = TIM2;
  comparator_timer_handle.Init.Prescaler = 0;
  comparator_timer_handle.Init.Period = 65536 - 1;
  comparator_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  comparator_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

  HAL_TIM_Base_Init(&comparator_timer_handle);
  HAL_TIM_Base_Start_IT(&comparator_timer_handle);

  comparator_ic_handle.ICPolarity = TIM_ICPOLARITY_RISING;
  comparator_ic_handle.ICSelection = TIM_ICSELECTION_DIRECTTI;
  comparator_ic_handle.ICPrescaler = TIM_ICPSC_DIV1;
  comparator_ic_handle.ICFilter = 0;

  HAL_TIM_IC_Init(&comparator_timer_handle);
  HAL_TIM_IC_ConfigChannel(&comparator_timer_handle, &comparator_ic_handle,
  TIM_CHANNEL_1);
  HAL_TIM_IC_Start_IT(&comparator_timer_handle, TIM_CHANNEL_1);

  HAL_NVIC_SetPriority(TIM2_IRQn, 0x01, 0x00);
  HAL_NVIC_EnableIRQ(TIM2_IRQn);

}

void init_printf_timer()
{
  __HAL_RCC_TIM5_CLK_ENABLE()
  ;
  printf_timer_handle.Instance = TIM5;
  printf_timer_handle.Init.Period = 10000;
  printf_timer_handle.Init.Prescaler = 10800;
  printf_timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  printf_timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;
  HAL_TIM_Base_Init(&printf_timer_handle);
  HAL_TIM_Base_Start_IT(&printf_timer_handle);
  HAL_NVIC_SetPriority(TIM5_IRQn, 0x01, 0x00);
  HAL_NVIC_EnableIRQ(TIM5_IRQn);
}

int main()
{
  MPU_Config();
  CPU_CACHE_Enable();
  HAL_Init();
  SystemClock_Config();
  init_motor_control_gpio_handle();
  init_motor_control_PWM_timer();
  init_potentiometer_handle();
  init_uart();
  init_comparator_gpio();
  init_comparator_timer();
  init_printf_timer();
  while (1)
  {

    //// PI not implemented yet

    HAL_ADC_Start(&adc_handle);
    if (HAL_ADC_PollForConversion(&adc_handle, 10) == HAL_OK)
    {
      inputRPM = HAL_ADC_GetValue(&adc_handle) * 81;
    }
    PI_controller();
    HAL_Delay(10);
  }
}


void TIM2_IRQHandler()
{
  HAL_TIM_IRQHandler(&comparator_timer_handle);
}

void TIM5_IRQHandler()
{
  HAL_TIM_IRQHandler(&printf_timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if (htim->Instance == TIM2)
  {
    overflow++;
  } else if (htim->Instance == TIM5)
  {
    printf("output RPM: %d\nctrl_out: %d\r\n", outputRPM, (int) ctrl_out);
  }
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
  timcounter++;
  int tim2CNT = TIM2->CNT;
  steps = overflow * 65535 + tim2CNT - previous;
  difference = timcounter - regitimcounter;
  regitimcounter = timcounter;
  previous = tim2CNT;
  freq = 108000000 / steps;
  outputRPM = (freq * 60) / 7;
  overflow = 0;
}

void PI_controller()
{
  err = inputRPM - outputRPM;
  integral = integral + err;
  ctrl_out = ((P * err + I * integral) / maxRPM) * 100;
  if (ctrl_out < 0)
  {
    ctrl_out = 0;
    integral -= err;
  } else if (ctrl_out > 100)
  {
    ctrl_out = 100;
    integral -= err;
  }
  __HAL_TIM_SET_COMPARE(&motor_pwm_timer_handle, TIM_CHANNEL_1, (int)ctrl_out);

}

static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  HAL_MPU_Disable();
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0x20010000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_256KB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
  HAL_MPU_ConfigRegion(&MPU_InitStruct);
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
  RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

  /**Configure the main internal regulator output voltage */
  __HAL_RCC_PWR_CLK_ENABLE()
  ;
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

  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /**Activate the Over-Drive mode */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }

  /**Initializes the CPU, AHB and APB busses clocks */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
      | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK)
  {
    Error_Handler();
  }
}

UART_PUTCHAR
{
  HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
  return ch;
}

static void CPU_CACHE_Enable(void)
{
    SCB_EnableICache();
    SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT

void assert_failed(uint8_t* file, uint32_t line)
{

    while (1)
    {
    }
}
#endif
