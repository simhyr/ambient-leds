#include "NeoPixel.h"

NeoPixel::NeoPixel(uint8_t pin, int count) : _pin(pin), _count(count)
{
    _strip = Adafruit_NeoPixel(_count, _pin, NEO_GRB | NEO_KHZ800);
}

void NeoPixel::setup(uint8_t brightness)
{
    _strip.begin();
    // intended to use in setup function only
    _strip.setBrightness(brightness);

    _strip.clear();
    _strip.show();

    _isSetup = true;
}

uint16_t NeoPixel::getPixelCount() {
    return _count;
}

uint32_t NeoPixel::_toNeoColorRGB(uint8_t red, uint8_t green, uint8_t blue)
{
    return _strip.Color(red, green, blue);
}

uint32_t NeoPixel::_toNeoColorHSV(uint16_t hue, uint8_t sat, uint8_t val)
{
    return _strip.ColorHSV(hue, sat, val);
}

void NeoPixel::setPixelColor(uint16_t index, uint32_t value, bool apply)
{
    if (index >= _count)
        return;

    _strip.setPixelColor(index, value);

    if (apply)
        _strip.show();
}

void NeoPixel::setPixelColorRGB(uint16_t index, uint8_t red, uint8_t green, uint8_t blue, bool apply)
{
    auto rgb = _toNeoColorRGB(red, green, blue);
    setPixelColor(index, rgb, apply);
}

// https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use HSV
// Multiple pixels can be set to the same color using the fill() function, which accepts one to three arguments. Typically it’s called like this:
// color, first, count

void NeoPixel::setPixelColorHSV(uint16_t index, uint16_t hue, uint8_t sat, uint8_t val, bool apply)
{
    auto hsv = _toNeoColorHSV(hue, sat, val);
    setPixelColor(index, hsv, apply);
}

void NeoPixel::setBrightness(uint8_t brightness)
{
    _strip.setBrightness(brightness);
}

void NeoPixel::clear()
{
    _strip.clear();
    _strip.show();
}