#include "../include/ToolClass.hpp"
#include "../include/Logger.hpp"

IniParse::IniParse::IniParse(const std::string &fileName) : _fileName(fileName) {}

std::map<std::string, std::map<std::string, std::string>> IniParse::IniParse::parseINI()
{
    std::ifstream file(_fileName);
    std::map<std::string, std::map<std::string, std::string>> iniData;
    std::string line;
    std::string currentSection;
    std::cout << " __FILE__ " << __FILE__ << " __LINE__ " << __LINE__ << std::endl;

    if (file.is_open())
    {
        std::cout << " open " << __LINE__ << std::endl;
        while (std::getline(file, line))
        {
            std::cout << " line " << line << std::endl;
            // 去掉行首尾的空白字符
            line.erase(0, line.find_first_not_of(" \t\r\n"));
            line.erase(line.find_last_not_of(" \t\r\n") + 1);
            std::cout << " line " << line << std::endl;
            // 跳过注释和空行
            if (line.empty() || line[0] == ';' || line[0] == '#')
                continue;

            // 判断是否是节
            if (line[0] == '[' && line[line.length() - 1] == ']')
            {
                currentSection = line.substr(1, line.length() - 2);
                continue;
            }

            // 解析键值对
            size_t delimiterPos = line.find('=');
            std::cout << " currentSection " << currentSection << std::endl;
            if (delimiterPos != std::string::npos)
            {
                std::string key = line.substr(0, delimiterPos);
                std::string value = line.substr(delimiterPos + 1);
                // 去除键和值两端的空白字符
                key.erase(0, key.find_first_not_of(" \t"));
                key.erase(key.find_last_not_of(" \t") + 1);
                value.erase(0, value.find_first_not_of(" \t"));
                value.erase(value.find_last_not_of(" \t") + 1);
                iniData[currentSection][key] = value;
            }
        }
        file.close();
    }
    else
    {
        // std::cout << " open " << __LINE__ << std::endl;
        Logger logger("/home/xdyun/xdyunGit/xdyunProject/HttpServer/logs/logfile.txt");
        logger.log(LogLevel::ERROR, "This is an error message.");
    }
    std::cout << " __FILE__ " << __FILE__ << " __LINE__ " << __LINE__ << std::endl;
    return iniData;
}