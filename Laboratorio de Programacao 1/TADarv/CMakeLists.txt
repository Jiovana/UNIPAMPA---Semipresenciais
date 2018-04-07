cmake_minimum_required(VERSION 3.8)
project(TADarv)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c arvore.c arvore.h)
add_executable(TADarv ${SOURCE_FILES})