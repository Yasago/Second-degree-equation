set(GCC_COVERAGE_COMPILE_FLAGS "-lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
cmake_minimum_required(VERSION 3.15)
project(equation C)

set(CMAKE_C_STANDARD 99)

add_executable(equation main.c equation.c equation.h testLib.c testLib.h)
target_link_libraries(equation m)