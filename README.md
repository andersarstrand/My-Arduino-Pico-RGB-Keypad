# My-Arduino-Pico-RGB-Keypad
This is my attempt to write a Arduino program for the `Pico RGB Keypad Base by Pimoroni`. 

The goal is to write all the code using the Arduino IDE and Arduino framework.

I´m using the board definitions from [Earle F. Philhower, III](https://github.com/earlephilhower/arduino-pico) for the Raspberry Pi Pico W.

I´m using the `Apa102-Arduino` library from [Pololu Robotics and Electronics](https://github.com/pololu/apa102-arduino) for interfacing to the LEDs on the Keypad.

I´m using the `TCA9555` library from [Rob Tillaart](https://github.com/RobTillaart/TCA9555) forinterfacing to the buttons on the Keypad.

NOTE: Not every library (example) will work "right out of the box".
* The LED´s are wired as a "Faux SPI" adding a chip select (CS) to the LED´s. This will require some additional code when addressing the LED´s.
* The I2C address for the Keypad (TCA9555) is by default set to 0x20. 

# Hardware
I´m using a `Raspbery Pi Pico W`  and the `Pico RGB Keypad Base by Pimoroni`.  

# Installation
It is possible to copy/clone this repo to your Arduino Library folder. Then the example code will appear in the example folder of the Arduino IDE.

# Links
* https://shop.pimoroni.com/products/pico-rgb-keypad-base
* https://www.raspberrypi.com/documentation/microcontrollers/raspberry-pi-pico.html

# Libraries and Boards
* https://github.com/earlephilhower/arduino-pico
* https://github.com/pololu/apa102-arduino
* https://github.com/RobTillaart/TCA9555
* https://cdn.shopify.com/s/files/1/0174/1800/files/pico_rgb_keypad_base_schematic.pdf?v=1629994431