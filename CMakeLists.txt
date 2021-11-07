# cmake_minimum_required(VERSION <specify CMake version here>)
project(TMPS)

set(CMAKE_CXX_STANDARD 20)

add_executable(TMPS
        main.cpp builder.h data.h network.h object.h softmax_singleton.h)
