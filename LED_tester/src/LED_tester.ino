/*
 * Project LED_tester
 * Description: LED tester
 * Author: Owen S
 * Date:
 */

#include "Neopixel.h"

const int PIXCELOUNT = 244;
const int PIXELPIN = D5;


Adafruit_NeoPixel pixel(PIXCELOUNT, PIXELPIN, WS2812B);

void pixelFill(int startPixel, int endPixel, int color);

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
    pixel.begin();
    pixel.setBrightness(100);
    pixel.show();

}

void loop() {
  pixelFill(0,244,0xFF0000);

}

void pixelFill(int startPixel, int endPixel, int color) {
  int i;
  for(i=startPixel; i<=endPixel; i++){
    pixel.setPixelColor(i, color);
  }
  pixel.show();
  delay(1000);
}