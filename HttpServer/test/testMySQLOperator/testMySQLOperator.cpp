#include "../include/MySQLOperator.hpp"
using namespace std;

int main()
{
    // 加载配置文件
    IniParse::IniParse iniParse("/home/xdyun/xdyunGit/xdyunProject/HttpServer/config/mysql.ini");

    // 读取INI文件
    auto mysqlIniMap = iniParse.parseINI();
    std::cout << " __FILE__ " << __FILE__ << " __LINE__ " << __LINE__ << std::endl;
    std::cout << mysqlIniMap.size() << std::endl;
    // for (auto it : mysqlIniMap)
    // {
    // }

    std::string database = mysqlIniMap["Mysql"]["database"];
    std::string password = mysqlIniMap["Mysql"]["password"];
    std::string username = mysqlIniMap["Mysql"]["username"];
    std::string localhost = mysqlIniMap["Mysql"]["ip"];
    // Connect to the MySQL database
    std::cout << "database :" << database << "password :" << password << "username :" << username
              << "localhost :" << localhost << std::endl;
    Database db(localhost, username, password, database);

    // Execute a query
    if (db.executeQuery("select * from PicKeyToValue;"))
    {
        std::cout << "Query executed successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to execute query!" << std::endl;
    }

    return 0;
}