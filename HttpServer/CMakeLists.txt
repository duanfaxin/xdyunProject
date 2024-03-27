cmake_minimum_required(VERSION 3.6)
project("MyPistacheProject")


include_directories ("/home/xdyun/tools/pistache/include/") 


add_executable(${PROJECT_NAME} httpServer.cpp)
target_link_libraries(${PROJECT_NAME} pistache)