// @File		WIRE.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		Brazil
// @Date		01/05/23
//
//
// Copyright (C) 2023  JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef WIRE_H
#define WIRE_H

#include <xc.h>

#define SCL             PORTAbits.RA1
#define SDA             PORTAbits.RA0

#define SCL_TRISB       TRISA1
#define SDA_TRISB       TRISA0

unsigned char Wire_Polling(unsigned char Slave);
unsigned char Wire_Nack(void);
unsigned char Wire_Ack(void);
void Wire_Stop(void);
void Wire_Start(void);
void Wire_Write(unsigned char data);
void Wire_Init(void);

#endif	

