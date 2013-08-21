/*
 * ks0108_Arduino.h - User specific configuration for ARM GLCD library
 *
 * Use this file to set io pins
 * This version is for a standard ks0108 display
 * connected using custom STM32F4 pin config.
 *
 * Config for every pin on different port
 *
 */

#ifndef GLCD_PIN_CONFIG_H
#define GLCD_PIN_CONFIG_H

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"

/*
 * define name for pin configuration
 */
#define glcd_PinConfigName "ks0108-STM32F4"

/* Low level GPIO config for STM32F4 */
#define LCDn 13

#if NBR_CHIP_SELECT_PINS > 2
#define LCDn 14
#endif
#if NBR_CHIP_SELECT_PINS > 3
#define LCDn 15
#endif

typedef enum
{
	glcdData0Pin = 0,
	glcdData1Pin = 1,
	glcdData2Pin = 2,
	glcdData3Pin = 3,
	glcdData4Pin = 4,
	glcdData5Pin = 5,
	glcdData6Pin = 6,
	glcdData7Pin = 7,
	glcdRW = 8,
	glcdDI = 9,
	glcdEN = 10,
	glcdCSEL1 = 11,
	glcdCSEL2 = 12
#if NBR_CHIP_SELECT_PINS > 2
	, glcdCSEL3 = 13
#endif
#if NBR_CHIP_SELECT_PINS > 3
	, glcdCSEL4 = 14
#endif
}	LCD_TypeDef;

#define glcdData0Pin_PIN	GPIO_Pin_12
#define glcdData0Pin_PORT	GPIOE
#define glcdData0Pin_CLK	RCC_AHB1Periph_GPIOE

#define glcdData1Pin_PIN	GPIO_Pin_13
#define glcdData1Pin_PORT	GPIOE
#define glcdData1Pin_CLK	RCC_AHB1Periph_GPIOE

#define glcdData2Pin_PIN	GPIO_Pin_14
#define glcdData2Pin_PORT	GPIOE
#define glcdData2Pin_CLK	RCC_AHB1Periph_GPIOE

#define glcdData3Pin_PIN	GPIO_Pin_15
#define glcdData3Pin_PORT	GPIOE
#define glcdData3Pin_CLK	RCC_AHB1Periph_GPIOE

#define glcdData4Pin_PIN	GPIO_Pin_8
#define glcdData4Pin_PORT	GPIOD
#define glcdData4Pin_CLK	RCC_AHB1Periph_GPIOD

#define glcdData5Pin_PIN	GPIO_Pin_9
#define glcdData5Pin_PORT	GPIOD
#define glcdData5Pin_CLK	RCC_AHB1Periph_GPIOD

#define glcdData6Pin_PIN	GPIO_Pin_10
#define glcdData6Pin_PORT	GPIOD
#define glcdData6Pin_CLK	RCC_AHB1Periph_GPIOD

#define glcdData7Pin_PIN	GPIO_Pin_11
#define glcdData7Pin_PORT	GPIOD
#define glcdData7Pin_CLK	RCC_AHB1Periph_GPIOD

#define glcdRW_PIN	GPIO_Pin_8
#define glcdRW_PORT	GPIOE
#define glcdRW_CLK	RCC_AHB1Periph_GPIOE

#define glcdDI_PIN	GPIO_Pin_7
#define glcdDI_PORT	GPIOE
#define glcdDI_CLK	RCC_AHB1Periph_GPIOE

#define glcdEN_PIN	GPIO_Pin_10
#define glcdEN_PORT	GPIOE
#define glcdEN_CLK	RCC_AHB1Periph_GPIOE

#define glcdCSEL1_PIN		GPIO_Pin_2
#define glcdCSEL1_PORT	GPIOA
#define glcdCSEL1_CLK		RCC_AHB1Periph_GPIOA

#define glcdCSEL2_PIN		GPIO_Pin_4
#define glcdCSEL2_PORT	GPIOC
#define glcdCSEL2_CLK		RCC_AHB1Periph_GPIOC

#if NBR_CHIP_SELECT_PINS > 2
#define glcdCSEL3_PIN		GPIO_Pin_
#define glcdCSEL3_PORT	GPIO
#define glcdCSEL3_CLK		RCC_AHB1Periph_GPIO
#endif
#if NBR_CHIP_SELECT_PINS > 3
#define glcdCSEL4_PIN		GPIO_Pin_
#define glcdCSEL4_PORT	GPIO
#define glcdCSEL4_CLK		RCC_AHB1Periph_GPIO
#endif

GPIO_TypeDef* LCD_PORT[LCDn] =
{ glcdData0Pin_PORT, glcdData1Pin_PORT, glcdData2Pin_PORT, glcdData3Pin_PORT, glcdData4Pin_PORT, glcdData5Pin_PORT,
		glcdData6Pin_PORT, glcdData7Pin_PORT, glcdRW_PORT, glcdDI_PORT, glcdEN_PORT, glcdCSEL1_PORT, glcdCSEL2_PORT
#if NBR_CHIP_SELECT_PINS > 2
	, glcdCSEL3_PORT
#endif
#if NBR_CHIP_SELECT_PINS > 3
	, glcdCSEL4_PORT
#endif
}	;
const uint16_t LCD_PIN[LCDn] =
{ glcdData0Pin_PIN, glcdData1Pin_PIN, glcdData2Pin_PIN, glcdData3Pin_PIN, glcdData4Pin_PIN, glcdData5Pin_PIN,
		glcdData6Pin_PIN, glcdData7Pin_PIN, glcdRW_PIN, glcdDI_PIN, glcdEN_PIN, glcdCSEL1_PIN, glcdCSEL2_PIN
#if NBR_CHIP_SELECT_PINS > 2
	, glcdCSEL3_PIN
#endif
#if NBR_CHIP_SELECT_PINS > 3
	, glcdCSEL4_PIN
#endif
}	;
const uint32_t LCD_CLK[LCDn] =
{ glcdData0Pin_CLK, glcdData1Pin_CLK, glcdData2Pin_CLK, glcdData3Pin_CLK, glcdData4Pin_CLK, glcdData5Pin_CLK,
		glcdData6Pin_CLK, glcdData7Pin_CLK, glcdRW_CLK, glcdDI_CLK, glcdEN_CLK, glcdCSEL1_CLK, glcdCSEL2_CLK
#if NBR_CHIP_SELECT_PINS > 2
	, glcdCSEL3_CLK
#endif
#if NBR_CHIP_SELECT_PINS > 3
	, glcdCSEL4_CLK
#endif
}	;

	/*********************************************************/
	/*  Configuration for assigning LCD bits to Arduino Pins */
	/*********************************************************/
	/* Data pin definitions
	 */
//#define glcdData0Pin        8
//#define glcdData1Pin        9
//#define glcdData2Pin        10
//#define glcdData3Pin        11
//#define glcdData4Pin        4
//#define glcdData5Pin        5
//#define glcdData6Pin        6
//#define glcdData7Pin        7
	/* Arduino pins used for Commands
	 * default assignment uses the first five analog pins
	 */

//#define glcdCSEL1        14
//#define glcdCSEL2        15
//
//#if NBR_CHIP_SELECT_PINS > 2
//#define glcdCSEL3            // third chip select if needed
//#error "Remove this notice if pin CS3 selected"
//#endif
//
//#if NBR_CHIP_SELECT_PINS > 3
//#define glcdCSEL4            // fourth chip select if needed
//#error "Remove this notice if CS3 selected"
//#endif
//#define glcdRW           16
//#define glcdDI           17
//#define glcdEN           18
// Reset Bit  - uncomment the next line if reset is connected to an output pin
//#define glcdRES          19    // Reset Bit
#endif //GLCD_PIN_CONFIG_H
