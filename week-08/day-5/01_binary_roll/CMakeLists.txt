cmake_minimum_required(VERSION 3.13)
project(01_binary_roll C)

set(CMAKE_C_STANDARD 99)

add_executable(01_binary_roll main.c binary_to_ascii.c binary_to_ascii.h)