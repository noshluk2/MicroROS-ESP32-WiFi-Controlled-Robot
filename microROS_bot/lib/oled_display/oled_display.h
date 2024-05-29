#ifndef OLED_DISPLAY_H
#define OLED_DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


void drawRightArrow(Adafruit_SSD1306 &display);
void drawLeftArrow(Adafruit_SSD1306 &display);
void drawForwardArrow(Adafruit_SSD1306 &display);
void drawBackwardArrow(Adafruit_SSD1306 &display);
void drawStopCircle(Adafruit_SSD1306 &display);

void setupDisplay(Adafruit_SSD1306 &display);
void displayLineFollowing(Adafruit_SSD1306 &display,int &lpwm,int &rpwm);

#endif
