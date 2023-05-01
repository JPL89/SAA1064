// @File		WIRE.C		 		
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
#include "wire.h"

#define _NOP() __asm__ __volatile__("nop")

void Wire_Start(void)
{
    SCL = 1;
    _NOP();
    SDA = 1;
    _NOP();
    SDA = 0;
    _NOP(); 
    SCL = 0;
}

void Wire_Stop(void)
{
    SDA = 0;
    _NOP();
    SCL = 1;
    _NOP(); 
    SDA = 1;
    
}

unsigned char Wire_Ack(void)
{
    unsigned char byte = 0;

    SDA_TRISB = 1;
    
    SDA = 1;
    
    for (unsigned char mask = 0x80; mask; mask >>= 1)
    {
        SCL = 1;
	_NOP();
        
	if(SDA == 1) byte |= mask; 
	
	SCL = 0;
        _NOP();
    }
	
    SDA_TRISB = 0;

    SDA = 0;
    _NOP();
    SCL = 1;
    _NOP();
    SCL = 0;
    _NOP();
    
    return byte;
}

unsigned char Wire_Nack(void)
{
    unsigned char byte = 0;
    
    SDA_TRISB = 1;
    
    SDA = 1;
    
    for (unsigned char mask = 0x80; mask; mask >>= 1)
    {
        SCL = 1;
	_NOP();
        
	if(SDA== 1) byte |= mask; 
	
	SCL = 0;
        _NOP();
    }
	
     SDA_TRISB = 0;

    SDA = 1;
    _NOP();
    SCL = 1;
    _NOP();
    SCL = 0;
    _NOP();
	
    return byte;
}

void Wire_Write(unsigned char data)
{
    for(unsigned char mask = 0x80; mask; mask >>= 1)
    {
	if(data & mask) SDA = 1; else SDA = 0;
	
        SCL = 1;
	_NOP();
	SCL = 0;
	_NOP();
    }
    
    SDA = 0;
    _NOP();
    SCL = 1;
    _NOP();
    SCL = 0;
    _NOP();
}

unsigned char Wire_Polling(unsigned char Slave)
{
    unsigned char ack = 0;
	
    Wire_Start();
    
    for(unsigned char mask = 0x80; mask; mask >>= 1)
    {
	if(Slave & mask) SDA = 1; else SDA = 0;
	
        SCL = 1;
	_NOP();
	SCL = 0;
	_NOP();
    }
        
    // Read ACK
    SDA_TRISB = 1;
    
    SDA = 1;
    _NOP();
    SCL = 1;
    _NOP();
    if(SDA == 1) ack = 1; 
    SCL = 0;
    _NOP();
    
    SDA_TRISB = 0;
    
    Wire_Stop();
    
    return ack;
}

void Wire_Init(void)
{
    SCL_TRISB = 0;
    SDA_TRISB = 0;
}

