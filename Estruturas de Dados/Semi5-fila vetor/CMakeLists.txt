cmake_minimum_required(VERSION 3.8)
project(Semi5)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c filas.c filas.h)
add_executable(Semi5 ${SOURCE_FILES})