cmake_minimum_required(VERSION 3.21)
project(Naval_War)

set(CMAKE_CXX_STANDARD 14)

add_executable(Naval_War main.cpp nava/nava.cpp nava/nava.h tipNave/salupa.cpp tipNave/salupa.h)
