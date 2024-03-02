# pH_EC_Controller

![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/InzynierDomu/pH_EC_Controller/main.yml?logo=github&style=flat-square)
![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/InzynierDomu/pH_EC_Controller?style=flat-square)
<a href="https://inzynierdomu.github.io/pH_EC_Controller/">![GitHub docs deployments](https://img.shields.io/github/deployments/InzynierDomu/pH_EC_Controller/github-pages?label=docs&logo=BookStack&logoColor=white&style=flat-square)</a>
<a href="https://discord.gg/KmW6mHdg">![Discord](https://img.shields.io/discord/815929748882587688?logo=discord&logoColor=green&style=flat-square)</a>
![GitHub](https://img.shields.io/github/license/InzynierDomu/PhECMeter?style=flat-square)
<a href="https://tipo.live/p/inzynierdomu">![support](https://img.shields.io/badge/support-tipo.live-yellow?style=flat-square)</a>

- [pH\_EC\_Controller](#ph_ec_controller)
  - [Description](#description)
  - [Scheme](#scheme)
    - [Part list](#part-list)
  - [IDE](#ide)

## Description

This is a more advanced version of the pH EC meter. Performing pH and EC measurements then turns on/off the relays depending on the level of measurements. It is used to automate the process of stabilization the target value pH and EC.
![photo](https://github.com/InzynierDomu/pH_EC_Controller/blob/main/schems/example_hw.jpg)
## Scheme
![schem](https://github.com/InzynierDomu/pH_EC_Controller/blob/main/schems/electrical/Screen.png)
Scheme prepared in kicad.
### Part list
* A1 Arduino Nano
* U1 ds18b20 temperature sensor
* J6 is socket for pH board.
* J7 is socket for EC board.
* J2 is socket for I2C screen HD44780 via PCF8574. 
* J5 is socket for SD card
* R2, R3 100k ohm resistors
* R1, R4, R5 4,7k ohm resistors
* Q1, Q2 2N700 N-channel MOSFETs
* Q3, Q4 BC547 NPN bipolar transistor
* K1, K2 relays 12VDC coil
* SW1 - SW2, SW4 - SW6 micro switches
* SW3 switch
* D1, D2 1N4007 diodes
* Connectors etc. 

## IDE

The project is prepared for the Platform IO environment. A video on how to install such an environment can be watched on this [video](https://youtu.be/Em9NuebT2Kc).
<br><br>
Formatting is done using clang-format. The description of the tool configuration is in the [video](https://youtu.be/xxuaOG0WjIE).
<br><br>
The code contains a comment prepared for doxygen, their use is described in the [video](https://youtu.be/1YKJtrCsPD4).
