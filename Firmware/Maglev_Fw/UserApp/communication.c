/* Includes ------------------------------------------------------------------*/
#include <stdarg.h>
#include "usart.h"
#include "lib_printf.h"
#include "communication.h"
/* Private define ------------------------------------------------------------*/
#define DEF_LIB_LOG_LINE_BUF_SIZE 64
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static char string_buffer[DEF_LIB_LOG_LINE_BUF_SIZE] = {0};
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void uart_print(const char *const fmt, ...)
{
	int len = 0;
	va_list  args;
	va_start(args, fmt);
	len += lib_vsnprintf(string_buffer, DEF_LIB_LOG_LINE_BUF_SIZE, fmt, args);
	va_end(args);
	HAL_UART_Transmit(&huart1, (uint8_t *)string_buffer, len, 0x40);
}