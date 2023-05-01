// @File		CONFIG.H		 		
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
#ifndef CONFIG_H
#define	CONFIG_H

// CONFIG1H
#pragma config OSC = HS         
#pragma config FCMEN = OFF      
#pragma config IESO = OFF       

// CONFIG2L
#pragma config PWRT = OFF       
#pragma config BOREN = OFF      
#pragma config BORV = 3         

// CONFIG2H
#pragma config WDT = OFF        
#pragma config WDTPS = 32768    

// CONFIG3H
#pragma config CCP2MX = PORTC   
#pragma config PBADEN = OFF     
#pragma config LPT1OSC = OFF    
#pragma config MCLRE = ON       

// CONFIG4L
#pragma config STVREN = OFF     
#pragma config LVP = OFF        
#pragma config XINST = OFF      

// CONFIG5L
#pragma config CP0 = OFF        
#pragma config CP1 = OFF        
#pragma config CP2 = OFF        
#pragma config CP3 = OFF        

// CONFIG5H
#pragma config CPB = OFF        
#pragma config CPD = OFF        

// CONFIG6L
#pragma config WRT0 = OFF       
#pragma config WRT1 = OFF       
#pragma config WRT2 = OFF       
#pragma config WRT3 = OFF       

// CONFIG6H
#pragma config WRTC = OFF       
#pragma config WRTB = OFF       
#pragma config WRTD = OFF       

// CONFIG7L
#pragma config EBTR0 = OFF      
#pragma config EBTR1 = OFF      
#pragma config EBTR2 = OFF      
#pragma config EBTR3 = OFF      

// CONFIG7H
#pragma config EBTRB = OFF     

#define _XTAL_FREQ   20000000

#include <xc.h>

void PIC18F2520(void)
{
    // CLEAR PORTS
    PORTA = 0x00;
    PORTB = 0x00;
    PORTC = 0x00;
    
    // CLEAR DATA LATCHES
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;
    
    // A/D PORT CONFIGURAION CONTROL BIT
    // (0x0F) DIGITAL I/O
    ADCON1 = 0x0F;
    
    // TURN OFF THE COMPARATORS
    CMCON = 0x07;    
}

#endif	/* CONFIG_H */

