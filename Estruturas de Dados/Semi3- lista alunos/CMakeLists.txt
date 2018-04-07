cmake_minimum_required(VERSION 3.8)
project(Semi3)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c aluno.c aluno.h)
add_executable(Semi3 ${SOURCE_FILES})