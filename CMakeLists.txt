cmake_minimum_required(VERSION 3.10)
project(leet LANGUAGES C CXX)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp)

target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -fsanitize=signed-integer-overflow -g)
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE -fsanitize=signed-integer-overflow)