cmake_minimum_required(VERSION 3.13)
project(01_smartphones C)

set(CMAKE_C_STANDARD 99)

add_executable(01_smartphones main.c smartphones.c smartphones.h)