#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

#define PIN            6
#define NUMPIXELS      4
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);

void setup() {

  // initialize leds and turn all off
  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(0, 0, 0));
  pixels.setPixelColor(1, pixels.Color(0, 0, 0));
  pixels.setPixelColor(2, pixels.Color(0, 0, 0));
  pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  pixels.show();
}

void loop() {

  // read the potentiometer value
  int potValue = analogRead(A0);

  // value goes from 0 to 1023, map the value on the led color
  if(potValue < 256) {
    pixels.setPixelColor(0, pixels.Color(potValue, 0, 0));
    pixels.setPixelColor(1, pixels.Color(0, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
  }
  else if(potValue < 512) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(potValue - 256, 0, 0));
    pixels.setPixelColor(2, pixels.Color(0, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));    
  }
  else if(potValue < 768) {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(potValue - 512, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, 0, 0));
  }
  else {
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(0, potValue - 768, 0));    
  }
  pixels.show();
  delay(50);

}
