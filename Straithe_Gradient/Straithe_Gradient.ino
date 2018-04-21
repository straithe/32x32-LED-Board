/*
 * Straithe_Gradient
 * 
 * Description: Creates a gradient down the board.
 * 
 * Written By:  Straithe
 * License:     Unlicense.
 */

#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

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
  drawGradient();
}


/*
 * Draws a gradient down the board.
 */
void drawGradient() 
{
  int       x, y;
  int       hue = 42; //Sets starting hue.
  uint16_t  colour;

  matrix.begin();

  // Chooses the current row to colour.
  for(y = 0; y < matrix.width(); y++) 
  {          
    hue += 10; //Adjust hue to change row colour.
    colour = matrix.ColorHSV(hue, 255, 255, true);

    // Draws the current color across the row.
    for(x = 0; x < matrix.height(); x++)
    {
      matrix.drawPixel(x, y, colour);
    }
  }
}

void loop() 
{
  // do nothing
}
