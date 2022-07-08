# pico_epd_1in54
Raspberry Pi Pico (RP2040) example interface code with E-Paper Display 1.54 inch from Wavesahre (Version v2).

## My Blog
https://andromedabay.ddns.net/controlling-1-54-inch-e-paper-via-pico/

## Youtube
[![Video of E-Paper Demo working](https://img.youtube.com/vi/lqd6cS6Fkh8/0.jpg)](https://www.youtube.com/watch?v=lqd6cS6Fkh8)

## Reference Links
https://www.raspberrypi.com/products/raspberry-pi-pico/

https://www.waveshare.com/product/displays/e-paper/1.54inch-e-paper-module.htm  (Version v2)

https://www.waveshare.com/wiki/1.54inch_e-Paper_Module     (Version v2)

https://github.com/waveshare/e-Paper   (Version v2)

https://www.digikey.ca/en/maker/projects/raspberry-pi-pico-rp2040-spi-example-with-micropython-and-cc/9706ea0cf3784ee98e35ff49188ee045

https://www.waveshare.com/wiki/Pico-ePaper-2.13

https://github.com/waveshare/Pico_ePaper_Code

## Pin Connections for Pico and E-Paper Display
![Pin Connections](/PinConnections.png)

## Pico Pin Layout
![Pico Pin Layout](/raspberry-pi-pico-pinout.png)

## WSL2 Reference

https://docs.microsoft.com/en-us/windows/wsl/about

https://docs.microsoft.com/en-us/windows/wsl/install


## Test Environment Setup
WSL2 on Windows 10 or 11, Visual Studio Code (VSCode).

Following link is a Beautiful Article by 'Paul Bupe, Jr',  describing WSL2 based C/C++ setup for Windows 10 and Up:
https://paulbupejr.com/raspberry-pi-pico-windows-development/

You may want to use following script to setup configure WSL2 as the Script in above article skips some official Repositories for Pico:
https://github.com/hammadrauf/pico-wsl-setup/blob/main/pico_setup.sh

To download this script in your home folder in WSL2 and run the following on the WSL2 prompts:
```
cd ~
sudo apt install -y git
git clone https://github.com/hammadrauf/pico-wsl-setup.git
/bin/bash ./pico-wsl-setup/pico_setup.sh
```

Configuring of Visual Studio Code is explained very nicely in the the article by Paul in section "Configure and Build with Visual Studio Code" in [the article link given above.](https://paulbupejr.com/raspberry-pi-pico-windows-development/ "Link to article")

## Utilities

Bitmap to Raw Data
https://www.waveshare.com/wiki/File:Image2Lcd.7z
