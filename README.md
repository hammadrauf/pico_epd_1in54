# pico_epd_1in54
Raspberry Pi Pico (RP2040) example interface code with E-Paper Display 1.54 inch from Wavesahre.

## Reference Links
https://www.raspberrypi.com/products/raspberry-pi-pico/

https://www.waveshare.com/product/displays/e-paper/1.54inch-e-paper-module.htm

https://www.waveshare.com/wiki/1.54inch_e-Paper_Module

https://www.waveshare.com/wiki/Pico-ePaper-2.13


## Test Environment
WSL2 on Windows 11, VSCode.

## Pin Connections for Pico and E-Paper Display
```
	+=======================================================================================================================+
	|	SYMBOL	DESCRIPTION						Pico Pin#				GPIO#			Active As			Master In/Out	|
	|	======	===========						=========				=====			=========			=============	|
	|	VCC		3.3V/5V							36/39																		|
	|	GND		Ground							23																			|
	|	DIN		SPI MOSI pin					25 (SPI0)				GP19								Out				|
	|	CLK		SPI SCK pin						24 (SPI0)				GP18								Out				|
	|	CS		SPI chip selection, low active	22 (Not in SPI0 mode)	GP17			Low					Out				|
	|	DC		Data/Command selection (high	26 (Any)				GP20			High – Data,		Out				|
	|			for data, low for command)												Low – Command						|
	|	RST		External reset, low active		27 (Any)				GP21			Low					Out				|
	|	BUSY	Busy status output, high active	29 (Any)				GP22			High				In				|
	+=======================================================================================================================+
```
![Pin Connections](/PinLayout.png)

