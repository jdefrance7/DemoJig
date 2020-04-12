#include "OLED.h"

// OLED Object
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

// Initialization function
int initOLED()
{
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    return -1;
  }

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(BUTTON_C, INPUT_PULLUP);
  
  return 0;
}
