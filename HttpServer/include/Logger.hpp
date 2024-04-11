#include <iostream>
#include <fstream>
#include <ctime>

enum class LogLevel
{
    DEBUG,
    INFO,
    WARNING,
    ERROR
};

class Logger
{
public:
    Logger(const std::string &filename);

    ~Logger();

    void log(LogLevel level, const std::string &message);

private:
    std::ofstream logFile;
};
