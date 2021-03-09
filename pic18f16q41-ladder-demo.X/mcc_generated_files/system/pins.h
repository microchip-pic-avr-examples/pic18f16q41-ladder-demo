/**
  Generated Pins header File

  Company:
    Microchip Technology Inc.

  File Name:
    pins.h

  Summary:
    This is generated driver header for pins. 

  Description:
    This header file provides APIs for all pins selected in the GUI.

  Generation Information:
    Driver Version:  3.0.0

*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RC2 aliases
#define OPAMP_OUT_TRIS                 TRISCbits.TRISC2
#define OPAMP_OUT_LAT                  LATCbits.LATC2
#define OPAMP_OUT_PORT                 PORTCbits.RC2
#define OPAMP_OUT_WPU                  WPUCbits.WPUC2
#define OPAMP_OUT_OD                   ODCONCbits.ODCC2
#define OPAMP_OUT_ANS                  ANSELCbits.ANSELC2
#define OPAMP_OUT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define OPAMP_OUT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define OPAMP_OUT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define OPAMP_OUT_GetValue()           PORTCbits.RC2
#define OPAMP_OUT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define OPAMP_OUT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define OPAMP_OUT_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define OPAMP_OUT_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define OPAMP_OUT_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define OPAMP_OUT_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define OPAMP_OUT_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define OPAMP_OUT_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PINS_H
/**
 End of File
*/