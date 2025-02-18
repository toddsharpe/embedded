# Embedded
Playing around with bare-metal embedded software. Currently supporting:
* STM32
* HiFive (RiscV)
* [Custom SoC (RiscV)](SoC/)

## Overview
* Bootloader + App
* Bootloader OTA update over UART (using Bluetooth/Hc06).
* Simple Kernel

### Boards
 * [NUCLEO-F746ZG](https://www.st.com/en/evaluation-tools/nucleo-f746zg.html)
 * [Disco-F746GNG](https://www.st.com/en/evaluation-tools/32f746gdiscovery.html)
 * [HiFive1 Rev B](https://www.sifive.com/boards/hifive1-rev-b)

### Drivers
* GPIO
* Simple UART
* SysTick
* Simple Timer
* Flash
* Spi/DMA

## Demos

### Threading
![Threading](Docs/Images/Threading.png)

### Updating
![Updating](Docs/Images/Updating.png)
