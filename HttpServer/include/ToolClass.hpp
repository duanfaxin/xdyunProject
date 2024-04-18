#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

namespace IniParse
{
    class IniParse
    {
    public:
        IniParse(const std::string &filename);

        /*
        这是一个ini 解析器  std::map<std::string, std::map<std::string, std::string>>  第一个是第一个字段  map对应的是内容
       */
        std::map<std::string, std::map<std::string, std::string>> parseINI();

    private:
        std::string _fileName;
    };
}
