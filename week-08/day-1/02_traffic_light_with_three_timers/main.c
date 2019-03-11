#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

#define UART_PUTCHAR int __io_putchar(int ch)

GPIO_InitTypeDef LEDS;
UART_HandleTypeDef UartHandle;

/* the timer's config structure */
TIM_HandleTypeDef TimHandle1;
TIM_HandleTypeDef TimHandle2;
TIM_HandleTypeDef TimHandle3;

uint16_t tim_val1 = 0;		/* variable to store the actual value of the timer's register (CNT) */
uint16_t tim_val2 = 0;
uint16_t tim_val3 = 0;
uint16_t seconds = 0;		/* variable to store the value of elapsed seconds */

static void Error_Handler(void);
static void SystemClock_Config(void);

int main(void)
{
    HAL_Init();

    __HAL_RCC_GPIOF_CLK_ENABLE();


    /* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
    SystemClock_Config();

    LEDS.Pin = GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10;
    LEDS.Mode = GPIO_MODE_OUTPUT_PP;
    LEDS.Pull = GPIO_NOPULL;
    LEDS.Speed = GPIO_SPEED_HIGH;

    __HAL_RCC_USART1_CLK_ENABLE();
    UartHandle.Instance = USART1;
    UartHandle.Init.BaudRate = 115200;
    UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
    UartHandle.Init.StopBits = UART_STOPBITS_1;
    UartHandle.Init.Parity = UART_PARITY_NONE;
    UartHandle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    UartHandle.Init.Mode = UART_MODE_TX_RX;
    BSP_COM_Init(COM1, &UartHandle);

    /* we need to enable the TIM2 */
    __HAL_RCC_TIM2_CLK_ENABLE();
    __HAL_RCC_TIM3_CLK_ENABLE();
    __HAL_RCC_TIM4_CLK_ENABLE();

    TimHandle1.Instance				= TIM2;
    TimHandle1.Init.Prescaler		= 54000 - 1;	/* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.5 ms */
    TimHandle1.Init.Period			= 24000 - 1;	/* 10000 x 0.5 ms = 1 second period */
    TimHandle1.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    TimHandle1.Init.CounterMode		= TIM_COUNTERMODE_UP;

    TimHandle2.Instance				= TIM3;
    TimHandle2.Init.Prescaler		= 54000 - 1;	/* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
    TimHandle2.Init.Period			= 24000 - 1;	/* 120000 x 0.1 ms = 12 second period */
    TimHandle2.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    TimHandle2.Init.CounterMode		= TIM_COUNTERMODE_UP;

    TimHandle3.Instance				= TIM4;
    TimHandle3.Init.Prescaler		= 54000 - 1;	/* 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms */
    TimHandle3.Init.Period			= 24000 - 1;	/* 120000 x 0.1 ms = 12 second period */
    TimHandle3.Init.ClockDivision	= TIM_CLOCKDIVISION_DIV1;
    TimHandle3.Init.CounterMode		= TIM_COUNTERMODE_UP;

    /* configure the timer */
    HAL_TIM_Base_Init(&TimHandle1);
    HAL_TIM_Base_Init(&TimHandle2);
    HAL_TIM_Base_Init(&TimHandle3);

    /* starting the timer */
    HAL_TIM_Base_Start(&TimHandle1);
    HAL_TIM_Base_Start(&TimHandle2);
    HAL_TIM_Base_Start(&TimHandle3);

    HAL_GPIO_Init(GPIOF, &LEDS);

    while (1) {

        /* blinking the user LED with 1 Hz (1 on and 1 off per seconds) */
    	tim_val1 = __HAL_TIM_GET_COUNTER(&TimHandle1);
        tim_val2 = __HAL_TIM_GET_COUNTER(&TimHandle2);
        tim_val3 = __HAL_TIM_GET_COUNTER(&TimHandle3);

        //RED

        if (tim_val1 == 12000) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
        }
        if (tim_val1 == 23999) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_RESET);
        }

        //YELLOW

        if (tim_val2 == 6000) {
           HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
        }
        if (tim_val2 == 12000) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
        }
        if (tim_val2 == 18000) {
           HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
        }
        if (tim_val2 == 23999) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
        }

        //GREEN

        if (tim_val3 == 0) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
        }
        if (tim_val3 == 6000) {
            HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
        }
    }
}

static void Error_Handler(void)
{}

static void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

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
    RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
        Error_Handler();
    }
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&UartHandle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
