#include "../include/Logger.hpp"

Logger::Logger(const std::string &filename)
{
    logFile.open(filename, std::ios::out | std::ios::app);
    if (!logFile.is_open())
    {
        std::cerr << "Error opening log file!" << std::endl;
    }
}

Logger::~Logger()
{
    if (logFile.is_open())
    {
        logFile.close();
    }
}

void Logger::log(LogLevel level, const std::string &message)
{
    std::time_t currentTime = std::time(nullptr); // 获取时间
    char timeString[100];
    std::strftime(timeString, sizeof(timeString), "%Y-%m-%d %H:%M:%S", std::localtime(&currentTime)); // 转成字符串

    std::string levelString;
    switch (level)
    {
    case LogLevel::DEBUG:
        levelString = "DEBUG";
        break;
    case LogLevel::INFO:
        levelString = "INFO";
        break;
    case LogLevel::WARNING:
        levelString = "WARNING";
        break;
    case LogLevel::ERROR:
        levelString = "ERROR";
        break;
    }

    if (logFile.is_open())
    {
        logFile << "[" << timeString << "] [" << levelString << "] " << message << std::endl;
    }
    else
    {
        std::cerr << "Log file is not open!" << std::endl;
    }
}