#include "../include/Logger.hpp"

int main()
{
    Logger logger("logfile.txt");

    logger.log(LogLevel::INFO, "This is an information message.");
    logger.log(LogLevel::DEBUG, "This is a debug message.");
    logger.log(LogLevel::WARNING, "This is a warning message.");
    logger.log(LogLevel::ERROR, "This is an error message.");

    return 0;
}