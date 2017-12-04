cmake_minimum_required(VERSION 3.8)
project(SPLLAb4)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c functions.h functions.c highOrderFunctions.h highOrderFunctions.c io.h io.c)
add_executable(SPLLAb4 ${SOURCE_FILES})