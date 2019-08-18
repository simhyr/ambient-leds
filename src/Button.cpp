#include "Button.h"

Button::Button(uint8_t pin) : _pin(pin) {}

void Button::_reset(bool state)
{
    _initState = state;
    _prevState = state;
}

// no internal pull down resistors
void Button::setup(uint8_t inputMode)
{
    pinMode(_pin, inputMode == INPUT_PULLUP ? INPUT_PULLUP : INPUT);
    _reset(inputMode == INPUT_PULLUP ? HIGH : LOW);
}

bool Button::isPressed()
{
    auto value = digitalRead(_pin) > 0 ? HIGH : LOW;

    // button is held
    if (value == _prevState)
        return false;

    // button is released
    if (value == _initState)
    {
        _prevState = value;
        return false;
    }

    // button is pressed
    _prevState = value;
    return true;
}