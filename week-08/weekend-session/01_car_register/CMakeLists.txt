cmake_minimum_required(VERSION 3.13)
project(01_car_register C)

set(CMAKE_C_STANDARD 99)

add_executable(01_car_register main.c car.h car.c)