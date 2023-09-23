#ifndef HC595_H
#define HC595_H
/* Includes ------------------------------------------------------------------*/
#include <stdbool.h>
#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
/* Define --------------------------------------------------------------------*/
#define HC595_DELAY_ENABLE 0 // 是否需要延时
/* Exported macro ------------------------------------------------------------*/
#define HC595_SI_HIGH() HAL_GPIO_WritePin(GPIOC, HC595_SI_Pin, GPIO_PIN_SET);
#define HC595_SI_LOW() HAL_GPIO_WritePin(GPIOC, HC595_SI_Pin, GPIO_PIN_RESET);
#define HC595_SCK_HIGH() HAL_GPIO_WritePin(GPIOC, HC595_SCK_Pin, GPIO_PIN_SET);
#define HC595_SCK_LOW() HAL_GPIO_WritePin(GPIOC, HC595_SCK_Pin, GPIO_PIN_RESET);
#define HC595_RCK_HIGH() HAL_GPIO_WritePin(GPIOC, HC595_RCK_Pin, GPIO_PIN_SET);
#define HC595_RCL_LOW() HAL_GPIO_WritePin(GPIOC, HC595_RCK_Pin, GPIO_PIN_RESET);

#if HC595_DELAY_ENABLE
#define HC595_DELAY(ms) vTaskDelay(ms)
#else
#define HC595_DELAY(ms)
#endif

#ifndef DEF_BIT_SET
#define DEF_BIT_SET(value, bit) ((value) |= (1UL << (bit)))
#endif

#ifndef DEF_BIT_CLEAR
#define DEF_BIT_CLEAR(value, bit) ((value) &= ~(1UL << (bit)))
#endif

/* Exported typedef ----------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported functions --------------------------------------------------------*/
void hc595_init(void);
void hc595_update(void);
void hc595_write_bit(uint8_t bit_n, bool i);
void hc595_write_byte(uint8_t byte);
#endif // HC595_H
