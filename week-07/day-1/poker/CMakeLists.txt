cmake_minimum_required(VERSION 3.13)
project(poker C)

set(CMAKE_C_STANDARD 99)

add_executable(poker main.c app_lib/poker.c app_lib/poker.h)