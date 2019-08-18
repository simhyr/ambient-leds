#include "Logger.h"

Logger::Logger(int baudrate) : _baudrate(baudrate) {}

void Logger::setup()
{
    Serial.begin(_baudrate);
}

void Logger::_log(String type, String message)
{
    Serial.println("[" + String(millis()) + "] " + type + " " + message);
}

void Logger::info(String message)
{
    this->_log("INFO", message);
}

void Logger::warn(String message)
{
    this->_log("WARN", message);
}

void Logger::debug(String message)
{
    this->_log("DEBUG", message);
}

void Logger::error(String message)
{
    this->_log("ERROR", message);
}