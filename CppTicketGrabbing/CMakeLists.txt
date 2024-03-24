cmake_minimum_required(VERSION 3.0)
project(MyCurlProject)

# 查找 cURL 库
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})

# 添加可执行文件
add_executable(my_curl_app ./src/main.cpp)

# 链接 cURL 库
target_link_libraries(my_curl_app ${CURL_LIBRARIES})
