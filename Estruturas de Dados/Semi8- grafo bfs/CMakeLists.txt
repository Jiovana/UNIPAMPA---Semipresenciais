cmake_minimum_required(VERSION 3.8)
project(Semi8)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c grafo.c grafo.h)
add_executable(Semi8 ${SOURCE_FILES})