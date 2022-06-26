# pico_epd_1in54
Raspberry Pi Pico (RP2040) example interface code with E-Paper Display 1.54 inch from Wavesahre.

## Reference Links
https://www.raspberrypi.com/products/raspberry-pi-pico/

https://www.waveshare.com/product/displays/e-paper/1.54inch-e-paper-module.htm

https://www.waveshare.com/wiki/1.54inch_e-Paper_Module

https://www.waveshare.com/wiki/Pico-ePaper-2.13

## Pin Connections for Pico and E-Paper Display
![Pin Connections](/PinConnections.png)

## Pico Pin Layout
![Pico Pin Layout](/raspberry-pi-pico-pinout.jpg)

## Test Environment
WSL2 on Windows 11, VSCode.

Following link is a Beautiful Article by 'Paul Bupe, Jr',  describing WSL2 setup for Windows 10 and Up:
https://paulbupejr.com/raspberry-pi-pico-windows-development/

You may want to use following script to setup configure WSL2 as the Script in above article skips some official Repositories for Pico:
https://github.com/hammadrauf/pico-wsl-setup/blob/main/pico_setup.sh

Save this script in your home folder in WSL2 and run the following on the WSL2 prompts:
```
cd ~
git clone https://github.com/hammadrauf/pico-wsl-setup.git
cd pico-wsl-setup
/bin/bash ./pico_setup.sh
```

Configuring of Visual Studio Code is explained very nicely in the the article by Paul in section "Configure and Build with Visual Studio Code" in the article link given above. [One] (https://paulbupejr.com/raspberry-pi-pico-windows-development/ "Two")

