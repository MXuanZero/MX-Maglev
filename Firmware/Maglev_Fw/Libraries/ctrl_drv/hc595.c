/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "hc595.h"
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static uint8_t hc595_byte = 0;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void hc595_init(void)
{
	HC595_RCK_HIGH();
	HC595_RCL_LOW();
	HC595_SI_LOW();
}

void hc595_update(void)
{
	uint8_t byte = hc595_byte;
	HC595_RCL_LOW();
	HC595_DELAY(1);
	for (uint8_t i = 0; i < 8; ++i) {
		HC595_SCK_LOW();
		HC595_DELAY(1);
		if ((byte & 0x80) != 0) {
			HC595_SI_HIGH();
		} else {
			HC595_SI_LOW();
		}
		HC595_DELAY(1);
		HC595_SCK_HIGH();
		HC595_DELAY(1);
		byte <<= 1;
	}
	HC595_DELAY(1);
	HC595_RCK_HIGH();
}

void hc595_write_bit(uint8_t bit_n, bool i)
{
	if (i) {
		DEF_BIT_SET(hc595_byte, bit_n);
	} else {
		DEF_BIT_CLEAR(hc595_byte, bit_n);
	}
}

void hc595_write_byte(uint8_t byte)
{
	hc595_byte = byte;
}