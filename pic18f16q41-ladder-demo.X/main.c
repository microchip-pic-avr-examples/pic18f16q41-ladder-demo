/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2023] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"

void moveResistorLadder(void)
{
    static volatile uint8_t ladderGain = 0;
    
    //Update the Resistor Ladder
    OPA1_SetResistorLadder(ladderGain);
    
    //Increment to the next ladder
    ladderGain++;
    
    //If we passed the last ladder step...
    if (ladderGain >= 8)
    {
        ladderGain = 0;
    }
    
    LED0_Toggle();
}

int main(void)
{
    SYSTEM_Initialize();
        
    //Activate Unity Gain
    OPA1_EnableSoftwareUnityGain();
    
    //Configure callback function
    Timer2_OverflowCallbackRegister(&moveResistorLadder);
    
    //Enable Interrupts
    INTERRUPT_GlobalInterruptEnable();
    
    //Start the Timer
    Timer2_Start();
    
    while (1)
    {
        
    }
    return 0;
}
