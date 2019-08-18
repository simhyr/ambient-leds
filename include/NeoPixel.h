#include "Microcontroller.h"

#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Adafruit_NeoPixel.h>

class NeoPixel
{
private:
    Adafruit_NeoPixel _strip;
    bool _isSetup = false;
    uint8_t _pin;
    uint16_t _count;
    uint32_t _toNeoColorRGB(uint8_t red, uint8_t green, uint8_t blue);
    uint32_t _toNeoColorHSV(uint16_t hue, uint8_t sat, uint8_t val);

public:
    // NeoPixel()=default; 
    NeoPixel(uint8_t pin, int count);
    void setup(uint8_t brightness = 255);
    uint16_t getPixelCount();
    void setPixelColor(uint16_t index, uint32_t value, bool apply = true);

    void setPixelColorRGB(uint16_t index, uint8_t red, uint8_t green, uint8_t blue, bool apply = true);
    // hue = color, sat = saturation (intensity of color), val = brightness
    void setPixelColorHSV(uint16_t index, uint16_t hue, uint8_t sat, uint8_t val, bool apply = true);

    void setBrightness(uint8_t brightness);
    void clear();
};

#endif