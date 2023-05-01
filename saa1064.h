// @File		SAA1064.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		01/05/23
//
//
// Copyright (C) 2023 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#ifndef SAA1064_H
#define SAA1064_H

#include "wire.h"

#define SAA1064_SLA_W 0x70
#define SAA1064_SLA_R 0x71

// ADDRESS MAP
#define SAA1064_CTRL	0x00
#define SAA1064_DIG1	0x01
#define SAA1064_DIG2	0x02
#define SAA1064_DIG3	0x03
#define SAA1064_DIG4	0x04
#define SAA1064_C0		0x01
#define SAA1064_C1		0x02
#define SAA1064_C2		0x04
#define SAA1064_C3		0x08
#define SAA1064_C4		0x10
#define SAA1064_C5		0x20
#define SAA1064_C6		0x40               

void SAA1064_Write_All
(unsigned char d1,unsigned char d2,unsigned char d3,unsigned char d4)
{
    Wire_Start();
    Wire_Write( SAA1064_SLA_W );
    Wire_Write( SAA1064_DIG1 );
    Wire_Write( d1 );
    Wire_Write( d2 );
    Wire_Write( d3 );
    Wire_Write( d4 );
    Wire_Stop();
}

void SAA1064_Write_One(unsigned char reg,unsigned char data)
{
    Wire_Start();
    Wire_Write( SAA1064_SLA_W );
    Wire_Write( reg );
    Wire_Write( data );
    Wire_Stop();
}

unsigned char SAA1064_Read_Status(void)
{
    unsigned char data = 0x00;
    Wire_Start();
    Wire_Write( SAA1064_SLA_R );
    data = Wire_Nack();
    Wire_Stop();      
    return ( data );
}

#endif
