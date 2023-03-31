

#include <APA102.h>

// Define which pins to use.
const uint8_t dataPin = 19;   // MOSI - PG19 on the Pico 
const uint8_t clockPin = 18;  // SCLK - PG18 on the Pico 
const uint8_t cs = 17;        // CS - GP17 on the Pico (inverted). The LED´s are wired as a Faux SPI with a chip select. 

// Create an object for writing to the LED strip.
APA102<dataPin, clockPin> ledStrip;

// Set the number of LEDs to control.
const uint16_t ledCount = 16;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color colors[ledCount];

// Set the brightness to use (the maximum is 31).
const uint8_t brightness = 1;



#include "Wire.h"
#include "TCA9555.h"


TCA9555 TCA(0x20); // The default adress on the Pico RGB base is 0x20


void setup() {
  Serial.begin(115200);

  // put your setup code here, to run once:
  pinMode(cs, OUTPUT); // Set the Chip Select pin to output.


  Wire.begin();
  TCA.begin();

}

void loop() {


  /* Loop over all pins/buttons.
  *  If the button is pushed (value is zero)
  *  Then set the color to with for that button
  *  Else set the coloe to black for that button
  */

  for (int pin = 0; pin < 16; pin++) // Loop over all pins
  {
    int val = TCA.digitalRead(pin); // Read the value 
    if (val == 0){
      colors[pin] = rgb_color(255, 255, 255);
    } else {
      colors[pin] = rgb_color(0, 0, 0);
    }

  }

  digitalWrite(cs, LOW); // Enable the LED´s 
  ledStrip.write(colors, ledCount, brightness); // Write the colors.
  digitalWrite(cs, HIGH); // Disable the LED´s

  delay(5);


}
