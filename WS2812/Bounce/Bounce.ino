/* Bounce pattern
 *  
 *  Bounce from one end of the strip and reverse direction
 *  Round robins between GRB colors for every step
 *  
 */

#define FASTLED_INTERNAL
#include <FastLED.h>

#define NUM_LEDS 30

#define DATA_PIN 2

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() {    
    FastLED.addLeds<WS2812, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical   
}

void loop(){
  // direction
  int x = 1;  

  int grb = 3;
  int index = grb - 1;
  for (int i = NUM_LEDS - 1; i >= 0;)
  {
    // round robin green red blue
    index = (index + 1) % grb;

    if (index == 0)
    {
      leds[i] = CRGB::Blue;
    }
    if (index == 1)
    {
      leds[i] = CRGB::Green;
    }
    if (index == 2)
    {
      leds[i] = CRGB::Red;    
    }
        
    //leds[i] = CRGB::Blue;
    FastLED.show();
    delay(100);
    leds[i] = CRGB::Black;

    // reverse direction
    if (i == 0)
    {
      x = -1;
    }
    // forward direction
    if (i == 29){
      x = 1;     
    }

    // next
    i-=x;    
  }
}
