cmake_minimum_required(VERSION 3.29)
project(test1)

set(CMAKE_CXX_STANDARD 20)

add_executable(test1
        "Homework 1.cpp"
        HardWheel.cpp
        Player.cpp
        Wheel.cpp)
