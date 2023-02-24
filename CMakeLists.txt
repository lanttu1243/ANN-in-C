cmake_minimum_required(VERSION 3.24)
project(ANN-in-C C)

set(CMAKE_C_STANDARD 23)

add_executable(ANN-in-C main.c matrix.c, matrix.h)
