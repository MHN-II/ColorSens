#include <Wire.h>
#include "Adafruit_TCS34725.h"
#define Led 9 
/* Example code for the Adafruit TCS34725 breakout library */

/* Connect SCL    to analog 5
   Connect SDA    to analog 4
   Connect VDD    to 3.3V DC
   Connect GROUND to common ground */
   
/* Initialise with default values (int time = 2.4ms, gain = 1x) */
// Adafruit_TCS34725 tcs = Adafruit_TCS34725();

/* Initialise with specific int time and gain values */
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);


void setup(void) {
  Serial.begin(9600);
  pinMode(Led, OUTPUT); 
  

  
  // Now we're ready to get readings!
}

void loop(void) {
  analogWrite(Led,225);
  uint16_t r, g, b, c, colorTemp, lux;
  
  tcs.getRawData(&r, &g, &b, &c);
  colorTemp = tcs.calculateColorTemperature(r, g, b);
  lux = tcs.calculateLux(r, g, b);

  
  /*Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
  Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - "); */
  Serial.print((r), DEC); Serial.print(",");
  Serial.print((g), DEC); Serial.print(",");
  Serial.print(b, DEC); Serial.println(".");
  //Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
}

