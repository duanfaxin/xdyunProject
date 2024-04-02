cmake_minimum_required(VERSION 3.6)
project("Pistache")


include_directories ("/home/xdyun/tools/pistache/include/") 


add_executable(${PROJECT_NAME} restServer.cpp)
target_link_libraries(${PROJECT_NAME} pistache)