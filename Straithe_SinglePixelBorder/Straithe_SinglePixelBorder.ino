/*
 * Straithe_SinglePixelBorder
 * 
 * Description: Single Pixel Border for 32 x 32 matrix
 * 
 * Written By:  Straithe
 * License:     
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
  drawBorder();
}

/*
 * Draws the border around the edge of the LED board.
 */
void drawBorder() 
{
  int      x, y;
  uint16_t c;

  matrix.begin();

  for(y = 0; y < matrix.width(); y++) 
  {      
    c = setColour();
    
    // Draw vertical line down on left
    x = 0;
    matrix.drawPixel(x, y, c);

    // Draw vertical line down on right
    x = matrix.width()-1;
    matrix.drawPixel(x, y, c);
  }

  for(x = 0; x < matrix.height(); x++)
  {   
    // Draw horizontal line at top
    y = 0;
    matrix.drawPixel(x, y, c);

    // Draw horizontal line at bottom
    y = matrix.height()-1;
    matrix.drawPixel(x, y, c);
  }
}

/* 
 * Set the colour for the border. 
 * return:  uint16_t  colour  colour for the border.
 */
uint16_t setColour() 
{
  uint16_t colour;

  colour = matrix.ColorHSV(42, 255, 255, true);

  return colour;
}

void loop() 
{
  // do nothing
}
