/*
 * ARMio.h
 *
 *  Created on: 21-08-2013
 *      Author: darklukee
 *
 * Copyright (C) 2013  darklukee
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see {http://www.gnu.org/licenses/}.
 */

#ifndef ARMIO_H_
#define ARMIO_H_

#include "../config/ks0108_Panel.h"
#include "stm32f4xx_gpio.h"

#define DIR_IN GPIO_Mode_IN
#define DIR_OUT GPIO_Mode_OUT

/*
 * TODO: 4bit not implemented
 */

static inline void ARMio_InitConfig(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;

	for (int i = 0; i <= LCDn; i++)
	{
		RCC_AHB1PeriphClockCmd(LCD_CLK[(LCD_PinDef) i], ENABLE);
		GPIO_InitStructure.GPIO_Pin = LCD_PIN[(LCD_PinDef) i];
		GPIO_Init(LCD_PORT[(LCD_PinDef) i], &GPIO_InitStructure);
	}
}

static inline void ARMio_WriteBit(LCD_PinDef pin, uint8_t val)
{
	GPIO_WriteBit(LCD_PORT[pin], LCD_PIN[pin], (BitAction) val);
}

static inline void ARMio_WriteByte(uint8_t data)
{
	for (int i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		ARMio_WriteBit((LCD_PinDef) i, data & (1 << i));
	}
}

static inline uint8_t ARMio_ReadBit(LCD_PinDef pin)
{
	return GPIO_ReadInputDataBit(LCD_PORT[pin], LCD_PIN[pin]);
}

static inline uint8_t ARMio_ReadByte()
{
	uint8_t data = 0;
	for (int i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		data |= (ARMio_ReadBit((LCD_PinDef) i) << i);
	}
	return data;
}

static inline void ARMio_SetPullUp(bool pull)
{
	for (int i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		GPIO_TypeDef* GPIOx = LCD_PORT[(LCD_PinDef) i];
		uint32_t currentpin = LCD_PIN[(LCD_PinDef) i];
		for (uint32_t pinpos = 0; pinpos < 0x10; pinpos++)
		{
			if (currentpin == (((uint32_t) 1) << pinpos))
			{
				/* Pull-up Pull down resistor configuration*/
				GPIOx->PUPDR &= ~(GPIO_PUPDR_PUPDR0 << ((uint16_t) pinpos * 2));
				GPIOx->PUPDR |= (((uint32_t) (pull ? GPIO_PuPd_UP : GPIO_PuPd_NOPULL)) << (pinpos * 2));
				break;
			}
		}
	}
}

static inline void ARMio_SetDirPin(LCD_PinDef pin, uint8_t dir)
{
	GPIO_TypeDef* GPIOx = LCD_PORT[pin];
	uint32_t currentpin = LCD_PIN[pin];
	for (uint32_t pinpos = 0; pinpos < 0x10; pinpos++)
	{
		if (currentpin == (((uint32_t) 1) << pinpos))
		{
			GPIOx->MODER &= ~(GPIO_MODER_MODER0 << (pinpos * 2));
			GPIOx->MODER |= (((uint32_t) ((dir == DIR_IN) ? GPIO_Mode_IN : GPIO_Mode_OUT)) << (pinpos * 2));
			break;
		}
	}
}

static inline void ARMio_SetDir(uint8_t dir)
{
	for (int i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		ARMio_SetDirPin((LCD_PinDef) i, dir);
	}
}
#endif /* ARMIO_H_ */
