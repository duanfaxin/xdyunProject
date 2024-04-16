#include "../include/MySQLOperator.hpp"

int main()
{
    // Connect to the MySQL database
    Database db("localhost", "username", "password", "database_name");

    // Execute a query
    if (db.executeQuery("INSERT INTO table_name (column1, column2) VALUES ('value1', 'value2')"))
    {
        std::cout << "Query executed successfully!" << std::endl;
    }
    else
    {
        std::cerr << "Failed to execute query!" << std::endl;
    }

    return 0;
}