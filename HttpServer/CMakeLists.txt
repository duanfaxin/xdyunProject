cmake_minimum_required(VERSION 3.6)
project("Pistache")


include_directories ("/home/xdyun/tools/pistache/include/") 
set(SOURCE_DIR src)
set(SOURCE_FILES ${SOURCE_DIR}/GetDisplayContent.cpp ${SOURCE_DIR}/Logger.cpp ${SOURCE_DIR}/MySQLOperator.cpp)

add_executable(${PROJECT_NAME} restServer.cpp ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} pistache)