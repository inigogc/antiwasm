#ifndef ANTIWASM_LOGGER_HPP
#define ANTIWASM_LOGGER_HPP

#include <iostream>
#include "logging_levels.hpp"

class Logger {
private:
    static LoggingLevel loggingLevel_;

public:
    static void Log(LoggingLevel minLoggingLevel, std::string logMessage);

    static void SetLoggingLevel(LoggingLevel loggingLevel);

    static LoggingLevel GetLoggingLevel();
};

#endif //ANTIWASM_LOGGER_HPP
