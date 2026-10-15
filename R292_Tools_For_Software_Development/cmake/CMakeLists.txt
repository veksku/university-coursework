cmake_minimum_required(VERSION 3.16)
project(ProgramName VERSION 1.0.0)

add_library(
    library
    lib.hpp
    lib.cpp
)

add_subdirectory(library_dir)

add_executable(program main.cpp)

target_link_libraries(program PRIVATE library)
