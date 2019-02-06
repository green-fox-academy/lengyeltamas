cmake_minimum_required(VERSION 3.13)
project(01_instrumentsToStringedInstruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_instrumentsToStringedInstruments main.cpp Instrument.cpp Instrument.h StringedInstrument.cpp StringedInstrument.h ElectricGuitar.cpp ElectricGuitar.h BassGuitar.cpp BassGuitar.h Violin.cpp Violin.h)