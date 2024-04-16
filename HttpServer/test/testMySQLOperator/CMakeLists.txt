cmake_minimum_required(VERSION 3.6)
project("MySQLOperator")


include_directories ("/home/xdyun/xdyunGit/xdyunProject/HttpServer/include") 
set(SOURCE_DIR /home/xdyun/xdyunGit/xdyunProject/HttpServer/src)
# set(SOURCE_FILES ${SOURCE_DIR}/GetDisplayContent.cpp ${SOURCE_DIR}/Logger.cpp ${SOURCE_DIR}/MySQLOperator.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/MySQLOperator.cpp testMySQLOperator.cpp )
 target_link_libraries(${PROJECT_NAME} -lmysqlclient)