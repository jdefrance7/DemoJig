#ifndef OLED_H
#define OLED_H

// Provides OLED object (oled) and init function.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED Buttons
#define BUTTON_A  9
#define BUTTON_B  6
#define BUTTON_C  5

// OLED Object
extern Adafruit_SSD1306 oled;

// Initialization function
int initOLED();

#endif
