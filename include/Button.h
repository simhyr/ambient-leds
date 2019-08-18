#include "Microcontroller.h"

#ifndef BUTTON_H
#define BUTTON_H

class Button
{
private:
    uint8_t _pin;
    bool _initState;
    bool _prevState;
    void _reset(bool initState);

public:
    Button(uint8_t pin);
    // INPUT_PULLUP mode button need to be connected to GND and GPIO
    // INPUT mode button need to be connected to VCC and GND + GPIO (using 10k resistor)
    void setup(uint8_t inputMode = INPUT);
    bool isPressed();
};

#endif