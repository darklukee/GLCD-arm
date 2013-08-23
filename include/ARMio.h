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

static inline void ARMio_WriteBit(uint8_t regtyp, avrpin_t pin, uint8_t val)
{

}

static inline void ARMio_WriteReg(uint8_t regtyp, uint8_t avrport, uint8_t data)
{

}


static inline uint8_t ARMio_ReadBit(uint8_t regtyp, avrpin_t avrpin)
{

}

static inline uint8_t ARMio_ReadReg(uint8_t regtyp, uint8_t avrport)
{

}

static inline void ARMio_Write8Bits(uint8_t regtyp, avrpin_t p0, avrpin_t p1, avrpin_t p2, avrpin_t p3, avrpin_t p4,
	avrpin_t p5, avrpin_t p6, avrpin_t p7, uint8_t data)
{

}

static inline uint8_t ARMio_Read8Bits(uint8_t regtyp, avrpin_t p0, avrpin_t p1, avrpin_t p2, avrpin_t p3, avrpin_t p4,
	avrpin_t p5, avrpin_t p6, avrpin_t p7)
{

}

static inline void ARMio_SetPullUp(void)
{
//set this up without messing up other
}

static inline void ARMio_SetDir(uint8_t dir)
{
#define DIR_IN 0x00
#define DIR_OUT 0xff
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_StructInit(&GPIO_InitStruct);
	if (dir == DIR_OUT) //default IN  in GPIO_StructInit();
		GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	//TODO: consider setting speed

	uint8_t lcdPins = 0;
	for(LCD_PinDef i = glcdData0Pin; i <= glcdData7Pin; i++)
	{
		if(lcdPins & (1 << i)) //pin set
			continue;

		GPIO_InitStruct.GPIO_Pin = LCD_PIN[i];
		lcdPins |= (1<<i);
		for(LCD_PinDef j = i+1; j <= glcdData7Pin; j++)
		{
			if(LCD_PORT[i] == LCD_PORT[j])
			{
				GPIO_InitStruct.GPIO_Pin |= LCD_PIN[j];
				lcdPins |= (i<<j);
			}
		}
		GPIO_Init(LCD_PORT[i], &GPIO_InitStruct);
	}
	if (lcdPins != 0xff)
		dummy("Not every pin was chceked, do something about me");
}
#endif /* ARMIO_H_ */
