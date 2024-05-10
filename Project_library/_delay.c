/*
 * _delay.c
 *
 *  Created on: Aug 2, 2023
 *      Author: Acer
 */



#include"_delay.h"
	void _delay_ms(unsigned long  Copy_uint32Delay)
	{
		for(unsigned long  i=0 ; i<(Copy_uint32Delay *4400) ; i++)
		{
			asm("NOP");
		}
	}

