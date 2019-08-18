#include "Potentiometer.h"

Potentiometer::Potentiometer(uint8_t pin) : _pin(pin) {}

void Potentiometer::setup()
{
    pinMode(_pin, INPUT);
}

long Potentiometer::read(long out_min, long out_max)
{
    auto value = analogRead(_pin);
    // long in_min, long in_max, long out_min, long out_max
    return map(value, 0, 1023, out_min, out_max);
}

uint8_t Potentiometer::readByte()
{
    return (uint8_t)read(0, 255);
}