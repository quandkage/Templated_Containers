cmake_minimum_required(VERSION 3.29)
project(Templated_Containers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lgcov")
add_executable(Templated_Containers main.cpp vector.hpp
        vector.cpp)
