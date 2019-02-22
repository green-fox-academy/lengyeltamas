cmake_minimum_required(VERSION 3.13)
project(exercise_3)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercise_3 main.cpp dish.cpp dish.h order.cpp order.h onlineOrder.cpp onlineOrder.h offlineOrder.cpp offlineOrder.h restaurant.cpp restaurant.h)