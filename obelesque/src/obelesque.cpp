/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/owenschwab/Documents/IoT/capstone/obelesque/src/obelesque.ino"
/*
 * Project obelesque
 * Description: Interactive sound + light installation
 * Author: Owen S
 * Date: 4/14/2023
 */

#include "Neopixel.h" 
#include "Adafruit_GFX.h" 
#include <math.h>

//SENSOR PINS
void setup();
void loop();
#line 13 "/Users/owenschwab/Documents/IoT/capstone/obelesque/src/obelesque.ino"
const int SENSOR1 = 12;
const int SENSOR2 = 13;
const int SENSOR3 = A5;
const int SENSOR4 = A4;
const int SENSOR5 = D8;
const int SENSOR6 = D7;
const int SENSOR7 = D6;
int inchOne, inchTwo, inchThree, inchFour, inchFive, inchSix, inchSeven;
int lastI1, lastI2, lastI3, lastI4, lastI5, lastI6, lastI7;
int i, j, pix, col;

//TONE PINS
const int TONE1 = D4;
const int TONE2 = A0;
const int TONE3 = D3;
const int TONE4 = A1;
const int TONE5 = D2;
const int TONE6 = A2;
const int TONE7 = A3;
int sound1, sound2, sound3, sound4, sound5, sound6, sound7;

//LED VARIABLES 
const int PIXELPIN = D5;
const int PIXELCOUNT = 245;
int pixel1, pixel2, pixel3, pixel4, pixel5, pixel6, pixel7;
int pixelA, pixelB, pixelC, pixelD, pixelE, pixelF, pixelG;
Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, WS2812B);
/*PIXEL LAYOUT: 
*BAR 1: 0-34 DOWN
*BAR 2: 35-69 UP
*BAR 3: 70-104 DOWN
*BAR 4: 105-139 UP
*BAR 5; 138-174 DOWN
*BAR 6: 175-209 UP
*BAR 7: 210-244 DOWN
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
void pixelFillClear(int start, int end, int color);
void pixelFillClearOPP(int start, int end, int color);
void pixelFillClearBOTH(int start, int end, int color);
void sensorPing(int SENSOR, int *INCHES);

SYSTEM_MODE(SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);

  pixel.begin();
  pixel.setBrightness(15); 
  pixel.show();

  pinMode(TONE6, OUTPUT);
  
}


void loop() {
  sensorPing(SENSOR1, &inchOne);
  sensorPing(SENSOR2, &inchTwo);
  sensorPing(SENSOR3, &inchThree);
  sensorPing(SENSOR4, &inchFour);
  sensorPing(SENSOR5, &inchFive);
  sensorPing(SENSOR6, &inchSix);
  sensorPing(SENSOR7, &inchSeven);

//   for(i=10; i<200; i++){
//       for(j=199; j<10; j--){}
//     pixel.setBrightness(i);
//     pixel.show();
//   }
// {
//     pixel.setBrightness(i);
//     pixel.show();
//   }

  // if(inchOne==lastI1 && inchTwo==lastI2 && inchThree==lastI3 && inchFour==lastI4 && inchFive==lastI5 && inchSix==lastI6 && inchSeven==lastI7){
  //   for(pix=34;pix>0;pix--){
  //     for(col=0;col<7;col++){
  //       pixel.setPixelColor(pixelMatrix[pix,col],0x0F0F0A);
  //     }
  //     pixel.show();
  //     delay(100);
  //   }
  // }


  if(inchOne>36){
    inchOne=36;
  }
  if(inchOne<12){
    inchOne=12;
  }

  if(inchTwo>36){
    inchTwo=36;
  }
  if(inchTwo<12){
    inchTwo=12;
  }

  if(inchThree>36){
    inchThree=36;
  }
  if(inchThree<12){
    inchThree=12;
  }

  if(inchFour>36){
    inchFour=36;
  }
  if(inchFour<12){
    inchFour=12;
  }

  if(inchFive>36){
    inchFive=36;
  }
  if(inchFive<12){
    inchFive=12;
  }

  if(inchSix>36){
    inchSix=36;
  }
  if(inchSix<12){
    inchSix=12;
  }

  if(inchSeven>36){
    inchSeven=36;
  }
  if(inchSeven<12){
    inchSeven=12;
  }

  if(inchOne!=lastI1){
    pixel1 = map(inchOne,36,12,17,0);
    pixelA = map(inchOne,36,12,18,34);
    pixelFillClear(pixel1,pixelA,0xFF0000);
    // sound1 = map(inchOne,72,0,1 ,301);
    // tone(TONE6, sound1, 500);
    Serial.printf("I1: %i | P1: %i | S1: %i\n\n", inchOne, pixel1, pixelA);
    lastI1=inchOne;
  }

  if(inchTwo!=lastI2){
    pixel2 = map(inchTwo,36,12,51,35);
    pixelB = map(inchTwo,36,12,52,69);
    pixelFillClearOPP(pixel2,pixelB,0x00FF00);
    //sound2 = map(inchTwo,72,0,0,602);
    //tone(TONE6, sound2, 500);
    Serial.printf("I2: %i | P2: %i | S2: %i\n\n", inchTwo, pixel2, pixelB);
    lastI2=inchTwo;
  }

  if(inchThree!=lastI3){
    //pixelFill(70,104,0x000000);
    pixel3 = map(inchThree,36,12,87,70);
    pixelC = map(inchThree,36,12,88,104);
    pixelFillClear(pixel3,pixelC,0x0000FF);
    // sound3 = map(inchThree,72,0,0,903);
    // tone(TONE6, sound3, 500);
    Serial.printf("I3: %i | P3: %i | S3: %i\n\n", inchThree, pixel3, sound3);
    lastI3=inchThree;
  }

  if(inchFour!=lastI4){
    //pixelFill(105,139,0x000000);
    pixel4 = map(inchFour,36,12,122,105);
    pixelD = map(inchFour,36,12,123,139);
    pixelFillClearOPP(pixel4,pixelD,0xFF0000);
    // sound4 = map(inchFour,72,0,0,1204);
    // tone(TONE6, sound4, 500);
    Serial.printf("I4: %i | P4: %i | S4: %i\n\n", inchFour, pixel4, sound4);
    lastI4=inchFour;
  }

  if(inchFive!=lastI5){
    pixel5 = map(inchFive,36,12,156,140);
    pixelE = map(inchFive,36,12,157,174);
    pixelFillClear(pixel5,pixelE,0x00FF00);
    // sound5 = map(inchFive,72,0,0,1505);
    // tone(TONE6, sound5, 500);
    Serial.printf("I5: %i | P5: %i | S5: %i\n\n", inchFive, pixel5, sound5);
    lastI5=inchFive;
  }  

  if(inchSix!=lastI6){
    pixel6 = map(inchSix,36,12,192,175);
    pixelF = map(inchSix,36,12,193,209);
    pixelFillClearOPP(pixel6,pixelF,0x00FF00);
    // sound6 = map(inchSix,72,0,0,1806);
    // tone(TONE6, sound6, 500);
    Serial.printf("I6: %i | P6: %i | S6: %i\n\n", inchSix, pixel6, sound6);
    lastI6=inchSix;
  }

  if(inchSeven!=lastI7){  
    pixel7 = map(inchSeven,36,12,227,210);
    pixelG = map(inchSeven,36,12,228,244);
    pixelFillClear(pixel7,pixelG,0x00FF00);
    // sound7 = map(inchSeven,72,0,0,2100);
    // tone(TONE6, sound7, 500);
    Serial.printf("I7: %i | P7: %i | S7: %i\n\n", inchSeven, pixel7, sound7);
    lastI7=inchSeven;
  }

}

void pixelFill(int startPixel, int endPixel, int color) {
  int i;
  for(i=startPixel; i<=endPixel; i++){
    pixel.setPixelColor(i, color);
    pixel.show();
  }   

}

void sensorPing(int SENSOR, int *INCHES) {
  int duration;
  pinMode(SENSOR, OUTPUT);
  digitalWrite(SENSOR, LOW);
  delay(1);
  digitalWrite(SENSOR, HIGH);
  delay(2);
  digitalWrite(SENSOR, LOW);
  pinMode(SENSOR, INPUT);
  duration = pulseIn(SENSOR, HIGH);
  *INCHES = duration/74/2;
}

void pixelFillClear(int start, int end, int color) {
  int neopixNum;
  const int TOTALPIXELS = 17; // Change this to match strip total length
  for (neopixNum = start; neopixNum < end; neopixNum ++) { // Fills given range with the set color
    pixel.setPixelColor(neopixNum, color);
    pixel.show();
  }
  for (neopixNum = end; neopixNum < end+TOTALPIXELS; neopixNum ++) { // Clears pixels above given range
    pixel.setPixelColor(neopixNum, 0xFFFFFF);
    pixel.show();
  }
  for (neopixNum = start; neopixNum > start-TOTALPIXELS; neopixNum --) { // Clears pixels below given range
    pixel.setPixelColor(neopixNum, 0xFFFFFF);
    pixel.show();
  }
}

void pixelFillClearOPP(int start, int end, int color) {
  int neopixNum;
  const int TOTALPIXELS = 17; // Change this to match strip total length
  for (neopixNum = end; neopixNum > start; neopixNum --) { // Fills given range with the set color
    pixel.setPixelColor(neopixNum, color);
    pixel.show();
  }
  for (neopixNum = end; neopixNum < end+TOTALPIXELS; neopixNum ++) { // Clears pixels above given range
    pixel.setPixelColor(neopixNum, 0xFFFFFF);
    pixel.show();
  }
  for (neopixNum = start; neopixNum > start-TOTALPIXELS; neopixNum --) { // Clears pixels below given range
    pixel.setPixelColor(neopixNum, 0xFFFFFF);
    pixel.show();
  }

}







