cmake_minimum_required(VERSION 3.13)
project(01_FleetOfThings)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_FleetOfThings main.cpp fleet.cpp fleet.h thing.cpp thing.h)