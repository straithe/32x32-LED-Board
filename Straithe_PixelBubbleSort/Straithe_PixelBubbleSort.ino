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

void setup() 
{
  int colorArray[32];
  
  matrix.begin();

  for(int y = 0; y < matrix.height(); y++) 
  {
    colorRow(y, colorArray);
    sortRow(y, colorArray);
  }
}

/* 
 * Sets the colors for the pixels in the row.
 * int y: the row to be colored
 * int colorArray[32]: holds the pixel hue values
 */
void colorRow(int y, int colorArray[32]) 
{
  int hue;
  uint16_t color;

  // For each pixel in the row, set a color and 
  //   add to the pixel color tracker array
  for(int x = 0; x < matrix.width(); x++) 
  {
    hue = rand() % 255 + 1;
    colorArray[x] = hue;
    color = matrix.ColorHSV(hue, 255, 255, true);
    matrix.drawPixel(x, y, color);
  }
}

/*
 * Sorts a row of pixels by hue value using bubblesort.
 * int y: the row to be sorted
 * int colorArray[32]: the color tracker array
 */
void sortRow(int y, int colorArray[32]) 
{
  uint16_t color;
  int temporaryHue1;
  int temporaryHue2;

  for(int i = 0; i < matrix.width(); i++) 
  {
    for(int x = 0; x < matrix.width()-1; x++) 
    {
      if(colorArray[x] > colorArray[x+1]) 
      {
        //Temporarily stores the colors to be swapped.
        temporaryHue1 = colorArray[x];
        temporaryHue2 = colorArray[x+1];

        // Applies the color for the first pixel to the second pixel
        color = matrix.ColorHSV(colorArray[x], 255, 255, true);
        matrix.drawPixel(x+1, y, color);

        // Applies the color for the second pixel to the first pixel
        color = matrix.ColorHSV(colorArray[x+1], 255, 255, true);
        matrix.drawPixel(x, y, color);

        // Swaps the colors in the color tracker array to
        //   match the current color of each pixel
        colorArray[x+1]=temporaryHue1;
        colorArray[x]=temporaryHue2;
        
        delay(50);
      }
    }
  }
}

void loop() 
{
  // do nothing
}
