cmake_minimum_required(VERSION 3.20)

project(compilation_test CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(../../constexpr_test)

add_executable(compilation_test main.cpp)
