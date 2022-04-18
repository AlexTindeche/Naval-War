cmake_minimum_required(VERSION 3.21)
project(Naval_War)

set(CMAKE_CXX_STANDARD 14)

add_executable(Naval_War main.cpp nava/nava.cpp nava/nava.h tipNave/salupa.cpp tipNave/salupa.h tipNave/submarin.cpp tipNave/submarin.h tipNave/distrugator.cpp tipNave/distrugator.h tipNave/crucisator.cpp tipNave/crucisator.h tipNave/crucisator_aparare.cpp tipNave/crucisator_aparare.h actiune/actiune.cpp actiune/actiune.h common.h)
