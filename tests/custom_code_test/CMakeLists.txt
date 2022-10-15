cmake_minimum_required(VERSION 3.20)

project(custom_code_test CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(../../constexpr_test)

add_executable(custom_code_test test.cpp)
