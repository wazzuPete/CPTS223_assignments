# Specify the minimum version of CMake required to build the project
cmake_minimum_required(VERSION 3.12)

# Set the project name and version
project(MyProject VERSION 1.0)

# Create an executable target for your C++ source files
add_executable(my_app main.cpp)

# Optionally, set C++ standard version (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
