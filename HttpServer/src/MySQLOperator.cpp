#include "../include/MySQLOperator.hpp"
#include <iostream>
#include <mysql/mysql.h>

class Database
{
public:
    Database(const std::string &host, const std::string &user, const std::string &password, const std::string &database)
    {
        mysql_init(&mysql);
        if (!mysql_real_connect(&mysql, host.c_str(), user.c_str(), password.c_str(), database.c_str(), 0, nullptr, 0))
        {
            std::cerr << "Error connecting to database: " << mysql_error(&mysql) << std::endl;
        }
    }

    ~Database()
    {
        mysql_close(&mysql);
    }

    bool executeQuery(const std::string &query)
    {
        if (mysql_query(&mysql, query.c_str()) != 0)
        {
            std::cerr << "Query execution error: " << mysql_error(&mysql) << std::endl;
            return false;
        }
        return true;
    }

private:
    MYSQL mysql;
};

// int main()
// {
//     // Connect to the MySQL database
//     Database db("localhost", "username", "password", "database_name");

//     // Execute a query
//     if (db.executeQuery("INSERT INTO table_name (column1, column2) VALUES ('value1', 'value2')"))
//     {
//         std::cout << "Query executed successfully!" << std::endl;
//     }
//     else
//     {
//         std::cerr << "Failed to execute query!" << std::endl;
//     }

//     return 0;
// }

// 实例  之后重写
// int main()
// {
//     MYSQL *conn;
//     MYSQL_RES *res;
//     MYSQL_ROW row;

//     conn = mysql_init(NULL);
//     if (conn == NULL)
//     {
//         std::cerr << "mysql_init() failed" << std::endl;
//         return 1;
//     }

//     conn = mysql_real_connect(conn, "hostname", "username", "password", "database", 0, NULL, 0);
//     if (conn == NULL)
//     {
//         std::cerr << "mysql_real_connect() failed: " << mysql_error(conn) << std::endl;
//         return 1;
//     }

//     if (mysql_query(conn, "SELECT * FROM your_table"))
//     {
//         std::cerr << "mysql_query() failed: " << mysql_error(conn) << std::endl;
//         return 1;
//     }

//     res = mysql_use_result(conn);
//     if (res == NULL)
//     {
//         std::cerr << "mysql_use_result() failed" << std::endl;
//         return 1;
//     }

//     while ((row = mysql_fetch_row(res)) != NULL)
//     {
//         for (int i = 0; i < mysql_num_fields(res); i++)
//         {
//             if (row[i] != NULL)
//                 std::cout << row[i] << " ";
//             else
//                 std::cout << "NULL ";
//         }
//         std::cout << std::endl;
//     }

//     mysql_free_result(res);
//     mysql_close(conn);

//     return 0;
// }