# tests/CMakeLists.txt

cmake_minimum_required(VERSION 3.28)
project(assignment_05 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_COMPILER clang)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

add_library(escape STATIC escape.c)
target_include_directories(escape PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(assignment_05 main.c)
target_link_libraries(assignment_05 escape)

enable_testing()
add_subdirectory(tests)
