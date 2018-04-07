cmake_minimum_required(VERSION 3.8)
project(Semi4)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c calculadora.c calculadora.h)
add_executable(Semi4 ${SOURCE_FILES})