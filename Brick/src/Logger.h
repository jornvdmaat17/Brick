#pragma once
#include "../lib/SimpleLogger.h"

namespace Brick {

    class Logger {
        public:
        static void logClientInfo(const std::string msg)
        {
            SimpleLogger::SimpleLogger::printTimeWithColor(SimpleLogger::BLACK, "CLIENT \tINFO: " + msg);
        }
        static void logClientWarn(const std::string msg)
        {
            SimpleLogger::SimpleLogger::printTimeWithColor(SimpleLogger::YELLOW, "CLIENT \tWARN: " + msg);
        }
        static void logClientError(const std::string msg)
        {
            SimpleLogger::SimpleLogger::printTimeWithColor(SimpleLogger::RED, "CLIENT \tERROR: " + msg);
        }

        static void logBrickInfo(const std::string msg)
        {
            SimpleLogger::SimpleLogger::printTimeWithColor(SimpleLogger::BLACK, "BRICK \tINFO: " + msg);
        }
        static void logBrickWarn(const std::string msg)
        {
            SimpleLogger::SimpleLogger::printTimeWithColor(SimpleLogger::YELLOW, "BRICK \tWARN: " + msg);
        }
        static void logBrickError(const std::string msg)
        {
            SimpleLogger::SimpleLogger::printTimeWithColor(SimpleLogger::RED, "BRICK \tERROR: " + msg);
        }
    };

}