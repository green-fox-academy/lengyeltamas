cmake_minimum_required(VERSION 3.13)
project(01_greenFoxOrganization)

set(CMAKE_CXX_STANDARD 14)

add_executable(01_greenFoxOrganization main.cpp person.cpp person.h student.cpp student.h mentor.cpp mentor.h sponsor.cpp sponsor.h cohort.cpp cohort.h)