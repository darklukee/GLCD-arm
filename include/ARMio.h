/*
 * ARMio.h
 *
 *  Created on: 21-08-2013
 *      Author: darklukee

 Copyright (C) 2013  darklukee

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see {http://www.gnu.org/licenses/}.
 */

#ifndef ARMIO_H_
#define ARMIO_H_

#include "../config/ks0108_Panel.h"
#include "stm32f4xx_gpio.h"

/*
 * TODO: 4bit not implemented
 */

static inline void ARMio_WriteBit(LCD_PinDef pin, uint8_t val)
{
	GPIO_WriteBit(LCD_PORT[pin], LCD_PIN[pin], (BitAction) val);
}

static inline void ARMio_WriteByte(uint8_t data)
{
	for (LCD_PinDef i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		ARMio_WriteBit(i, data & (1 << ((uint8_t) i)));
	}
}

static inline uint8_t ARMio_ReadBit(LCD_PinDef pin)
{
	return GPIO_ReadInputDataBit(LCD_PORT[pin], LCD_PIN[pin]);
}

static inline uint8_t ARMio_ReadByte()
{
	uint8_t data = 0;
	for (LCD_PinDef i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		data |= (ARMio_ReadBit(i) << ((uint8_t) i));
	}
	return data;
}

static inline void ARMio_SetPullUp(bool pull)
{
// TODO: set this up without messing up other
	uint32_t pinpos = 0x00;

	for (LCD_PinDef i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		GPIO_TypeDef* GPIOx = LCD_PORT[i];
		pinpos = LCD_PIN[i];
		/* Pull-up Pull down resistor configuration*/
		GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t) pinpos * 2));
		GPIOx->PUPDR |= (((uint32_t) (pull ? GPIO_PuPd_UP : GPIO_PuPd_NOPULL)) << (pinpos * 2));
	}
}

static inline void ARMio_SetDirPin(LCD_PinDef pin, uint8_t dir)
{
#define DIR_IN 0x00
#define DIR_OUT 0xff
	GPIO_TypeDef* GPIOx = LCD_PORT[pin];
	uint32_t pinpos = LCD_PIN[pin];

	GPIOx->MODER &= ~(GPIO_MODER_MODER0 << (pinpos * 2));
	GPIOx->MODER |= (((uint32_t) ((dir == DIR_IN) ? GPIO_Mode_IN : GPIO_Mode_OUT)) << (pinpos * 2));
}

static inline void ARMio_SetDir(uint8_t dir)
{
#define DIR_IN 0x00
#define DIR_OUT 0xff

	for (LCD_PinDef i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		GPIO_TypeDef* GPIOx = LCD_PORT[i];
		uint32_t pinpos = LCD_PIN[i];

		GPIOx->MODER &= ~(GPIO_MODER_MODER0 << (pinpos * 2));
		GPIOx->MODER |= (((uint32_t) ((dir == DIR_IN) ? GPIO_Mode_IN : GPIO_Mode_OUT)) << (pinpos * 2));
	}
}
#endif /* ARMIO_H_ */
