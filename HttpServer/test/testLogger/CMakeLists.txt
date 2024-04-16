cmake_minimum_required(VERSION 3.6)
project("Logger")


include_directories ("/home/xdyun/xdyunGit/xdyunProject/HttpServer/include") 
set(SOURCE_DIR /home/xdyun/xdyunGit/xdyunProject/HttpServer/src)
# set(SOURCE_FILES ${SOURCE_DIR}/GetDisplayContent.cpp ${SOURCE_DIR}/Logger.cpp ${SOURCE_DIR}/MySQLOperator.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_DIR}/Logger.cpp testLogger.cpp )
# target_link_libraries(${PROJECT_NAME} Logger)