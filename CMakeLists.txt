cmake_minimum_required(VERSION 3.10)
project(PA3)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB_RECURSE SOURCES src/*.cpp)

foreach(SOURCE ${SOURCES})
    message("Found source file: ${SOURCE}")
endforeach()

add_executable(PA3 ${SOURCES})