#include "../include/GetDisplayContent.hpp"
#include <vector>

int main()
{
    std::string line = "temp 30 comp = 0.1";
    std::vector<std::pair<double, int>> vect;
    //.(temp30comp)
    std::string findTmpName = "temp";
    // 30 85 105 150
    findTmpName += std::to_string(150);
    std::string filePath = "";

    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "无法打开文件" << std::endl;
        return false;
    }
    std::string line;
    while (getline(file, line))
    {
        // 逐行读取
        // line = "temp30comp = 0.1"
        int tmpnum = 0;
        if (line.substr(0, 4) == "temp")
        {
            int i = 4;

            while (line[i] != 'c')
            {
                tmpnum = tmpnum * 10 + line[i] - '0';
            }
        }

        auto index = line.find('=');
        std::string endNum = line.substr(index);
        double n = atof(endNum.c_str());
        vect.push_back({n, tmpnum});
    }
    return true;
}