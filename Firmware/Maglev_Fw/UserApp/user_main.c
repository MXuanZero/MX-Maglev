/* Includes ------------------------------------------------------------------*/
#include <stdarg.h>
#include "user_main.h"
#include "usart.h"
#include "FreeRTOS.h"
#include "task.h"
#include "adc.h"
#include "lib_printf.h"
#include "communication.h"
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
uint16_t adc_val[3] = { 0 };

void user_main(void)
{
	HAL_ADC_Start_DMA(&hadc1, (uint32_t *)adc_val, 3);

	for (;;) {
		uart_print("adc1=%d, adc2=%d, adc3=%d\r\n", adc_val[0], adc_val[1], adc_val[2]);
		vTaskDelay(100);
	}
}