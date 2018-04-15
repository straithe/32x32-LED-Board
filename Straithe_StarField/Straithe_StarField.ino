/*
 * Straithe_BubbleSort
 * 
 * Description: Bubblesorts a 32x32 LED board row by row.
 * 
 * Written By:  Straithe
 * License:     Unlicense.
 */

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library
#include <stdlib.h>

// pinout for 32x32 matrix
#define CLK 11
#define OE  9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false);

void setup() {  
  matrix.begin();
}

/* 
 * Sets the colors for the pixels in the row.
 * int y: the row to be colored
 * int colorArray[32]: holds the pixel hue values
 */
void colorPixels() {
  int hue;
  int saturation;
  int x;
  int y;
  uint16_t color;
  
  hue = rand() % 255;
  saturation = rand() % 255;
  x = rand() % 32;
  y = rand() % 32;
  color = matrix.ColorHSV(hue, saturation, 255, true);
  matrix.drawPixel(x, y, color);
  delay(200);
}

void blankPixels() {
  int x;
  int y;
  uint16_t color;
  
  x = rand() % 32;
  y = rand() % 32;
  color = matrix.ColorHSV(0, 0, 0, true);
  matrix.drawPixel(x, y, color);
  delay(200);
}

void loop() {
 colorPixels();
 blankPixels();
}
