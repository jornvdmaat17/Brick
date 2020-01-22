#ifndef _simple_logger_h_
#define _simple_logger_h_

#include <iostream>
#include <ctime>

namespace SimpleLogger {

    enum Color 
    {
        RED = 31,
        YELLOW = 33,
        BLACK = 39
    };

    class SimpleLogger {
        private:
        static const std::string getTimestamp()
        {
            auto t = std::time(0);
            auto now = std::localtime(&t);
            return std::string("[") + std::to_string(now->tm_hour) + ":" + std::to_string(now->tm_min) + ":" + std::to_string(now->tm_sec) + "]";
        }

        static const std::string formatColorString(Color c)
        {
            return "\033[" + std::to_string(c) + "m";
        }

        public:
        static void printTimeWithColor(Color c, const std::string msg)
        {
            std::cout << getTimestamp() << " " << formatColorString(c) << msg << formatColorString(BLACK) << std::endl;
        }
    };
};

#endif