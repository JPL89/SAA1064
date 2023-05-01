// @File		NAIN.C		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		Brazil
// @Date		01/05/23
//
//
// Copyright (C) 2021  JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
#include "config.h"
#include "wire.h"
#include "saa1064.h"

#define SAA61064_CTRL_DEFINIED          (SAA1064_C0|SAA1064_C1|SAA1064_C2|SAA1064_C5)

static const unsigned char font1[] = 
{
    0x3F,  //0
    0x06,  //1
    0x5B,  //2
    0x4F,  //3
    0x66,  //4
    0x6D,  //5
    0x7D,  //6
    0x07,  //7
    0x7F,  //8
    0x6F,  //9
    0x77,  //A
    0x7C,  //B
    0x39,  //C
    0x5E,  //D
    0x79,  //E
    0x71,  //F
};   

void main(void)
{     
    PIC18F2520();
    
    Wire_Init();
        
    SAA1064_Write_One(SAA1064_CTRL, SAA61064_CTRL_DEFINIED);

    SAA1064_Write_All(font1[1],font1[9],font1[8],font1[5]);
    
    while(1) {};
    
    return;
}
