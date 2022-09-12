<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Gain Ladder Demonstration for PIC18F16Q41
The operational amplifier (OPA) module on the PIC18F16Q41 family of devices comes with an internal resistor ladder that can be used to set different gains internally. This code example demonstrates how to use the internal resistor ladder to generate various DC levels without the use of a DAC.

## Related Documentation

[Code Example: AVR128DB48 Using the Internal Opamp as Regulated Power Supply for MVIO (MPLAB)](https://github.com/microchip-pic-avr-examples/avr128db48-using-opamp-as-a-regulated-power-supply-mplab)  
[Code Example: AVR128DB48 Using the Internal Opamp as Regulated Power Supply for MVIO (Studio)](https://github.com/microchip-pic-avr-examples/avr128db48-using-opamp-as-a-regulated-power-supply)  

## Software Used  
* [MPLAB® X IDE v6.0.0 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-x-ide?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-ladder-demo-github)
* [Microchip XC8 Compiler v2.40.0 or newer](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-ladder-demo-github)
* [MPLAB® Code Configurator (MCC) v5.1.16 or newer](https://www.microchip.com/en-us/tools-resources/configure/mplab-code-configurator?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-ladder-demo-github)

## Hardware Used

**Note: Version 2.0.0 of this project switched to the Curiosity Nano. Previous versions used the Curiosity Development Board (DM164137).**

* [PIC18F16Q41 Curiosity Nano Evaluation Kit (EV26Q64A)](https://www.microchip.com/en-us/development-tool/EV26Q64A?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-ladder-demo-github)
* [Curiosity Nano Adapter Board (AC164162)](https://www.microchip.com/en-us/development-tool/AC164162?utm_source=GitHub&utm_medium=TextLink&utm_campaign=MCU8_MMTCha_pic18q41&utm_content=pic18f16q41-ladder-demo-github)

## Pin Table
| Pin | Function
| --- | --------
| RC2 | Output of the OPA module
| RC7 | LED0

## Operation  
The internal resistor ladder of the OPA module is normally used to provide feedback for the operational amplifier. In this code example, the internal resistor ladder is used to generate a voltage level based on the internal resistor ladder. The output of the operational amplifier is proportional to the resistor divider network created between Vdd and Vss, as shown below. GSEL (gain select) is the internal name for the resistor ladder.

![Schematic](./images/schematic.png)   
*Internal Connections*

The table below (reproduced from the device datasheet) contains the ratios of the internal resistors available in PIC18F16Q41.

| Resistor Ratio   | Output %      | Ideal Output at Vdd = 3.3V
| ---------------- | ------------- | -------
| 1/15             | 6.25%         | 206.25mV
| 1/7              | 12.5%         | 412.5mV
| 1/3              | 25%           | 825mV
| 1                | 50%           | 1.65V
| 5/3              | 62.5%         | 2.0625V
| 3                | 75%           | 2.475V
| 7                | 87.5%         | 2.8875V
| 15               | 93.75%        | 3.09375V

*Expected Outputs in the Gain Ladder*

To demonstrate the full range of outputs, the code example generates a free-running sawtooth waveform (shown below) that contains all of the output steps listed above. The LED toggles on each ladder step. 

![Gain Ladder Output](./images/demoOutput.PNG)  
*Gain Ladder Output*  

## Summary
This code example demonstrates the internal resistor ladder to generate various DC output levels. 