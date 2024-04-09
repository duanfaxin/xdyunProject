#ifndef __GETDISPLAYCONTENT_H__
#define __GETDISPLAYCONTENT_H__
#include <iostream>
#include <fstream>
using namespace std;

/*
 *文件读取器
 */
class FileReadTool
{
public:
    bool readFromFileToString(std::string filePath);

    std::string getContent();

    bool Clear();

private:
    std::string fileContent;
    std::string _filePath;
};
#endif