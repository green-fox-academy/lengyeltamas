cmake_minimum_required(VERSION 3.13)
project(02)

set(CMAKE_CXX_STANDARD 14)

add_executable(02 main.cpp employee.cpp employee.h waiter.cpp waiter.h chef.cpp chef.h manager.cpp manager.h restaurant.cpp restaurant.h)