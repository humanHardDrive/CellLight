// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels
#define BLEND_TIME  1000

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  randomSeed(analogRead(A0));  

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

uint8_t targetColor[3] = { 0 };
uint8_t startColor[3] = { 0 };
uint8_t currentColor[3] = { 0 };

uint32_t nTick = 0;

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'

  if (memcmp(currentColor, targetColor, 3) == 0)
  {
    memcpy(startColor, currentColor, 3);
    targetColor[0] = random(256);
    targetColor[1] = random(256);
    targetColor[2] = random(256);

    nTick = 0;
  }

  for (uint8_t i = 0; i < 3; i++)
  {
    int32_t tempColor;

    tempColor = (((int32_t)(targetColor[i] - startColor[i])) * nTick);
    tempColor /= BLEND_TIME;
    tempColor += startColor[i];

    currentColor[i] = (uint8_t)tempColor;
  }

  pixels.setPixelColor(0, pixels.Color(currentColor[0], currentColor[1], currentColor[2]));

  nTick++;

  pixels.show();   // Send the updated pixel colors to the hardware.

  delay(DELAYVAL); // Pause before next pass through loop
}
