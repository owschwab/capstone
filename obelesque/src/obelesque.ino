/*
 * Project obelesque
 * Description: Interactive sound + light installation
 * Author: Owen S
 * Date: 4/14/2023
 */

#include "Neopixel.h"
#include <math.h>

//SENSOR PINS
const int SENSOR1 = 
const int SENSOR2 = 
const int SENSOR3 =
const int SENSOR4 =
const int SENSOR5 = 
const int SENSOR6 =
const int SENSOR7 = 
int inchOne, inchTwo, inchThree, inchFour, inchFive, inchSix, inchSeven;

//LED VARIABLES 
const int PIXELPIN = 
const int PIXELCOUNT = 245;
Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, WS2812B);
/*PIXEL LAYOUT: 
*BAR 1: 0-34
*BAR 2: 35-69
*BAR 3: 70-104
*BAR 4: 105-139
*BAR 5; 138-174
*BAR 6: 175-209
*BAR 7: 210-244
*/

int pixelMatrix[] { 0, 69,  70, 139, 140, 209, 210,
                    1, 68,  71, 138, 141, 208, 211,
                    2, 67,  72, 137, 142, 207, 212,
                    3, 66,  73, 136, 143, 206, 213,
                    4, 65,  74, 135, 144, 205, 214,
                    5, 64,  75, 134, 145, 204, 215,
                    6, 63,  76, 133, 146, 203, 216,
                    7, 62,  77, 132, 147, 202, 217,
                    8, 61,  78, 131, 148, 201, 218,
                    9, 60,  79, 130, 149, 200, 219,
                   10, 59,  80, 129, 150, 199, 220,
                   11, 58,  81, 128, 151, 198, 221,
                   12, 57,  82, 127, 152, 197, 222,
                   13, 56,  83, 126, 153, 196, 223,
                   14, 55,  84, 125, 154, 195, 224,
                   15, 54,  85, 124, 155, 194, 225,
                   16, 53,  86, 123, 156, 193, 226,
                   17, 52,  87, 122, 157, 192, 227,
                   18, 51,  88, 121, 158, 191, 228,
                   19, 50,  89, 120, 159, 190, 229,
                   20, 49,  90, 119, 160, 189, 230,
                   21, 48,  91, 118, 161, 188, 231,
                   22, 47,  92, 117, 162, 187, 232,
                   23, 46,  93, 116, 163, 186, 233,
                   24, 45,  94, 115, 164, 185, 234,
                   25, 44,  95, 114, 165, 184, 235,
                   26, 43,  96, 113, 166, 183, 236,
                   27, 42,  97, 112, 167, 182, 237,
                   28, 41,  98, 111, 168, 181, 238,
                   29, 40,  99, 110, 169, 180, 239,
                   30, 39, 100, 109, 170, 179, 240,
                   31, 38, 101, 108, 171, 178, 241,
                   32, 37, 102, 107, 172, 177, 242,
                   33, 36, 103, 106, 173, 176, 243,
                   34, 35, 104, 105, 174, 175, 244,};

void pixelFill(int startPixel, int endPixel, int color);
void sensorPing(int SENSOR, int *INCHES);

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600):

  pixel.begin();
  pixel.show();
  
}


void loop() {


}

void pixelFill(int startPixel, int endPixel, int color) {
  int i;
  for(i=startPixel; i<=endPixel; i++){
    pixel.setPixelColor(i, color);
  }
  pixel.show();
}

void sensorPing(int SENSOR, int *INCHES) {
  int duration;
  pinMode(SENSOR, OUTPUT);
  digitalWrite(SENSOR, LOW);
  delay(1);
  digitalWrite(SENSOR, HIGH);
  delay(5);
  digitalWrite(SENSOR, LOW);
  pinMode(SENSOR, INPUT);
  duration = pulseIn(SENSOR, HIGH);
  *INCHES = duration/74/2;
}