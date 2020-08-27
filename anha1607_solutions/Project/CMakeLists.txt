cmake_minimum_required(VERSION 3.13)
project(Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(Project
        src/constants.h
        src/functions.cpp
        src/functions.h
        src/main.cpp src/constants.h src/functions.h src/functions.cpp)
