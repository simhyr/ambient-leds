#include "Microcontroller.h"

#ifndef LOGGER_H
#define LOGGER_H

class Logger
{
private:
    int _baudrate;
    void _log(String type, String message);

public:
    Logger(int baudrate);
    void setup();

    void info(String message);
    void warn(String message);
    void debug(String message);
    void error(String message);
};

#endif