cmake_minimum_required(VERSION 3.13)
project(03_petrolStation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(03_petrolStation
        car.cpp
        car.h
        main.cpp
        station.cpp
        station.h)
