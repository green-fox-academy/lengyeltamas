#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "SystemClock_Config.h"

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    BSP_LED_Init(LED_GREEN);
    while (1) {
        BSP_LED_Toggle(LED_GREEN);
        HAL_Delay(500);
    }
}