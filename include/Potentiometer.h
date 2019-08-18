#include "Microcontroller.h"

#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

class Potentiometer
{
private:
    uint8_t _pin;

public:
    Potentiometer(uint8_t pin);
    void setup();
    long read(long out_min, long out_max);
    uint8_t readByte();
};

#endif