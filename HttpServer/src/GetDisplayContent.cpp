#include "../include/GetDisplayContent.hpp"

using namespace std;

bool FileReadTool::readFromFileToString(std::string filePath)
{
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
        fileContent += line;
    }
    return true;
}

std::string FileReadTool::getContent()
{
    return fileContent;
}

bool FileReadTool::Clear()
{
    fileContent = "";
    return true;
}