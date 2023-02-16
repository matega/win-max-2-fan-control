# GPD Win Max 2 Fan Speed Control

This is a quick-and-dirty proof of concept for controlling the fan speed of tha AMD version GPD Win Max 2 laptop.

## Building

Build with `make all`. Output will be `dist/Release/GNU-Linux/winmax2fancontrol`

## Usage

Run as root.

`winmax2fancontrol <option>`, where \<option\> is either `a` for auto or a number between 0 and 184, inclusive for a fixed speed.

## Disclaimer

Use at your own risk. The method was discovered by disassembling the MotionAssistant utility, which is only available on Windows.

