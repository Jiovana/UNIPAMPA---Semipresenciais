cmake_minimum_required(VERSION 3.8)
project(Locadora)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c Locadora.c Locadora.h)
add_executable(Locadora ${SOURCE_FILES})