#include <iostream>
#include <mysql/mysql.h>
#include "ToolClass.hpp"

class Database
{
public:
    Database(const std::string &host, const std::string &user, const std::string &password, const std::string &database);

    ~Database();

    bool executeQuery(const std::string &query);

private:
    MYSQL mysql;
};
