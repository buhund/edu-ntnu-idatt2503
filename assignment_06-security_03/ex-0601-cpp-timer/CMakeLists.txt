cmake_minimum_required(VERSION 3.29)
project(ex_06_cpp_timer)

# Set C++ standard to 20 and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(ex_06_cpp_timer main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")

# OpenSSL paths
include_directories(/usr/local/ssl/include)
link_directories(/usr/local/ssl/lib)

# Link against OpenSSL
target_link_libraries(ex_06_cpp_timer ssl crypto)
