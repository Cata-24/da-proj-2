cmake_minimum_required(VERSION 3.30)
project(2a2s_da_proj_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(2a2s_da_proj_2 main.cpp
        interface.h
        interface.cpp
        structs.h
        interface.cpp
        startup.h
        pallet.h
        pallet.cpp
        solver.h
        solver.cpp
        ilp_utils.h
        ilp_utils.cpp)
