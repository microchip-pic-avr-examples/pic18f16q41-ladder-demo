<!-- Please do not change this html logo with link -->
<a href="https://www.microchip.com" rel="nofollow"><img src="images/microchip.png" alt="MCHP" width="300"/></a>

# Gain Ladder Demonstration for PIC18F16Q41
The operational amplifier (OPA) module on the PIC18-Q41 family of devices comes with an internal resistor ladder that can be used to set different gains internally. This code example shows an alternative mode of operation where the ladder is instead used to create static DC levels.

## Software Used
* <a href="http://www.microchip.com/mplab/mplab-x-ide">MPLAB® IDE 5.40 or newer</a>
* <a href="https://www.microchip.com/mplab/compilers">Microchip XC8 Compiler 2.20 or newer</a>
* <a href="https://www.microchip.com/mplab/mplab-code-configurator">MPLAB® Code Configurator (MCC) 3.95.0 or newer</a>

## Hardware Used
- <a href="https://www.microchip.com/wwwproducts/en/PIC18F16Q41">PIC18F16Q41 Product Information</a>
- <a href="https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM164137"> Microchip Curiosity Development Board (DM164137) </a>

## Setup
| Pin | Function
| --- | --------
| RC2 | Output of the OPA module

## Operation
<img src="images/gainLevelDemo.PNG" alt="Gain Waveform" width="500px"/><br>
*Figure 1 - Gain Ladder Output*<br>

By default, this code example generates a sawtooth waveform containing all of the resistor ratios available in the OPA Module. The output of each step is a function of the resistor ratio inside the device. Table 1 shows the output % of Vdd and the expected output for a part running on 5V.

| R2/R1 Ratio   | Output %      | Expected Output at Vdd = 5V   |
| ------------- | ------------- | ----------------------------- |
| 1/15          | 6.25%         | 312.5mV                       |
| 1/7           | 12.5%         | 625mV                         |
| 1/3           | 25%           | 1.25V                         |
| 1             | 50%           | 2.5V                          |
| 5/3           | 62.5%         | 3.125V                        |
| 3             | 75%           | 3.75V                         |
| 7             | 87.5%         | 4.375V                        |
| 15            | 93.75%        | 4.6875V                       |

*Table 1 - Expected Outputs in the Gain Ladder*
## Summary
This code example shows an alternative use for the internal resistor ladder of the PIC18F16Q41. The ladder can be used for DC levels in applications or can be used to calculate the internal resistor ratios on the bench.
