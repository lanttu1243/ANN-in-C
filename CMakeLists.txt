cmake_minimum_required(VERSION 3.24)
project(ANN-in-C C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 23)

set(SOURCE_FILES main.c)

add_executable(ANN-in-C matrix.c)
