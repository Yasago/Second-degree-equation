cmake_minimum_required(VERSION 3.15)
project(equation C)

set(CMAKE_C_STANDARD 99)

add_executable(equation main.c equation.c equation.h testLib.c testLib.h)