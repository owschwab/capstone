/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/owenschwab/Documents/IoT/CapStoneTesting/ultrasonicTesting/src/ultrasonicTesting.ino"
/*
 * Project ultrasonicTesting
 * Description:
 * Author:
 * Date:
 */
#include "Neopixel.h"

void setup();
void loop();
#line 9 "/Users/owenschwab/Documents/IoT/CapStoneTesting/ultrasonicTesting/src/ultrasonicTesting.ino"
const int PINGPIN = D3;
const int PIXELPIN = D5;
const int PIXELCOUNT = 30;

int duration, inches, topPixel, bottomPixel, lastInches;

Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, WS2812B);

void pixelFill(int startPixel, int endPixel, int color);

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);

  pixel.begin();
  pixel.setBrightness(10);
  pixel.show();

}


void loop() {
  pinMode(PINGPIN, OUTPUT);
  digitalWrite(PINGPIN, LOW);
  delay(1);
  digitalWrite(PINGPIN, HIGH);
  delay(5);
  digitalWrite(PINGPIN, LOW);

  pinMode(PINGPIN, INPUT);
  duration = pulseIn(PINGPIN, HIGH);

  inches = duration/74/2;

  if(inches>72){
    inches=lastInches;
  }

  if(inches!=lastInches){
    pixel.clear();
    pixel.show();
    topPixel = map(inches,65,0,0,30);
    pixelFill(0, topPixel, 0x00ff00);
    Serial.printf("D; %i I: %i\n",duration, inches);
    lastInches=inches;
  }

}

void pixelFill(int startPixel, int endPixel, int color) {
  int i;
  for(i=startPixel; i<=endPixel; i++){
    pixel.setPixelColor(i, color);
  }
  pixel.show();
}