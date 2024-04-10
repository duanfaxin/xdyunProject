#include "../include/GetDisplayContent.hpp"
#include <iostream>
#include <sstream>

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

bool FileReadTool::readImagesToString(std::string imagePath)
{
    Clear();
    std::ifstream imageFile(imagePath, std::ios::binary);
    if (imageFile)
    {
        std::ostringstream oss;
        oss << imageFile.rdbuf();
        fileContent = oss.str();
        return true;
    }
    else
    {
        std::cout << "not found" << endl;
        return false;
    }
}