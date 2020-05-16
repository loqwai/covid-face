// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 2 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(64, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup()
{
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  pixels.clear();
}

byte image[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

void loop()
{

  pixels.clear(); // Set all pixel colors to 'off'
  for (int i = 0; i < 64; i++)
  {
    writePixel(i);
  }
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(DELAYVAL); // Pause before next pass through loop
}

void writePixel(int index)
{
  //1. get image coordinate
  byte x = getXCoordinate(index);
  byte y = getYCoordinate(index);
  byte color = image[y][x];
  if (color == 1)
  {
    pixels.setPixelColor(index, pixels.Color(255, 255, 255));
  }
  else
  {
    pixels.setPixelColor(index, pixels.Color(0, 0, 0));
  }
}

// Input: a number from 0 to 63
// Output: the x coordinate of the index
byte getXCoordinate(byte index)
{
  byte rowNumber = getYCoordinate(index);

  //If we're on an even row
  if (rowNumber % 2 == 0)
  {
    return index % 8;
  }
  return 7 - (index % 8);
}

byte getYCoordinate(byte index)
{
  return index / 8;
}
