#include <Microcontroller.h>
#include "NeoPixel.h"
#include "Logger.h"

NeoPixel _pixel(D1, 24);
Logger _logger(9600);

void setup() {
  _pixel.setup();
  _logger.setup();
}

uint16_t _hue = 0;
void loop() {
  if(_hue >= 0xFFFF)
     _hue = 0;

  //_logger.info(String(_hue, HEX));
  for(uint16_t i = 0; i < _pixel.getPixelCount(); i++) {
    _pixel.setPixelColorHSV(i, _hue, 0xFF, 0xFF);
  }

  _hue += 200;
}