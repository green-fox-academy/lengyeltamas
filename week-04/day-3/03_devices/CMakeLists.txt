cmake_minimum_required(VERSION 3.13)
project(03_devices)

set(CMAKE_CXX_STANDARD 14)

add_executable(03_devices main.cpp Printer.cpp Printer.h Printer3D.cpp Printer3D.h Printer2D.cpp Printer2D.h Scanner.cpp Scanner.h Copier.cpp Copier.h)