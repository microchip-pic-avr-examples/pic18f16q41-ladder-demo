/*
Copyright (c) [2012-2020] Microchip Technology Inc.  

    All rights reserved.

    You are permitted to use the accompanying software and its derivatives 
    with Microchip products. See the Microchip license agreement accompanying 
    this software, if any, for additional info regarding your rights and 
    obligations.

    MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
    WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
    LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
    AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
    LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
    LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
    THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
    LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
    OR OTHER SIMILAR COSTS. 

    To the fullest extend allowed by law, Microchip and its licensors 
    liability will not exceed the amount of fees, if any, that you paid 
    directly to Microchip to use this software. 
    
    THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
    third party software accompanying this software is subject to the terms 
    and conditions of the third party's license agreement.  To the extent 
    required by third party licenses covering such third party software, 
    the terms of such license will apply in lieu of the terms provided in 
    this notice or applicable license.  To the extent the terms of such 
    third party licenses prohibit any of the restrictions described here, 
    such restrictions will not apply to such third party software.
*/
#include "mcc_generated_files/system/system.h"

//Set the resistor ladder
#define SetResistorLadder(X) OPA1CON1bits.GSEL = ratioValue

//Init the OPAMP
void initOPAMP()
{
    OPA1CON0 = 0x00;
    OPA1CON1 = 0x00;
    OPA1CON2 = 0x00;
    OPA1CON3 = 0x00;
    
    //EN = 0, CPON = 1, UG = 1, SOC = 00
    OPA1CON0 = 0x48;
    
    //GSEL = 000, RESON = 1, NSS = 111
    OPA1CON1 = 0x0F;
    
    //PCH = 001, NCH = 000
    OPA1CON2 = 0x01;
    
    //FMS = 01, PSS = 000
    OPA1CON3 = 0x40;
    
    OPA1CON0bits.EN = 1;
}

int main(void)
{
    SYSTEM_Initialize();
    
    // Init the OPAMP
    initOPAMP();
    
    uint8_t ratioValue = 0;
        
    while (1)
    {
        //The code below takes ~60us to execute - only delay for 40
        __delay_us(40);
        
        // Change the output
        SetResistorLadder(ratioValue);
        
        // Increment to the next ratio
        ratioValue++;
        
        //Valid range is 0 to 7 for GSEL
        if (ratioValue >= 8)
            ratioValue = 0x0;
    }
    return 0;
}
