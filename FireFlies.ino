#include <Adafruit_NeoPixel.h>

#define PIN D6
#define Pixels 168

Adafruit_NeoPixel strip = Adafruit_NeoPixel(Pixels, PIN, NEO_GRB + NEO_KHZ800);

float redStates[Pixels];
float blueStates[Pixels];
float greenStates[Pixels];
float fadeRate = 0.96;

void setup() {  
  strip.begin();
  strip.show();
  
  for(uint16_t l = 0; l < Pixels; l++) {
    redStates[l] = 0;
    greenStates[l] = 0;
    blueStates[l] = 0;
  }
}

void loop () {
  
   if (random(20) == 1) {
      int i = random(Pixels);
      if (redStates[i] < 1 && greenStates[i] < 1 && blueStates[i] < 1) {
        redStates[i] = random(256);
        greenStates[i] = random(256);
        blueStates[i] = random(256);
      }
    }
    
    for(int l = 0; l < Pixels; l++) {
      if (redStates[l] > 1 || greenStates[l] > 1 || blueStates[l] > 1) {
        strip.setPixelColor(l, redStates[l], greenStates[l], blueStates[l]);
        
        if (redStates[l] > 1) {
          redStates[l] = redStates[l] * fadeRate;
        } else {
          redStates[l] = 0;
        }
        
        if (greenStates[l] > 1) {
          greenStates[l] = greenStates[l] * fadeRate;
        } else {
          greenStates[l] = 0;
        }
        
        if (blueStates[l] > 1) {
          blueStates[l] = blueStates[l] * fadeRate;
        } else {
          blueStates[l] = 0;
        }
        
      } else {
        strip.setPixelColor(l, 0,0,0);
      }
    }
    strip.show();
    delay(7); //Change this value to determine the speed of the pattern
}
