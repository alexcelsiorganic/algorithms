cmake_minimum_required(VERSION 3.17)
project(ones)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,10000000")
set(CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_executable(ones main.cpp)