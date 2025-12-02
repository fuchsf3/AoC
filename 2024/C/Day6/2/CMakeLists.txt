cmake_minimum_required(VERSION 3.10)
project(AoC)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB SOURCES
    "${SRC_DIR}/*.h"
    "${SRC_DIR}/*.c"
)

add_executable(${PROJECT_NAME} ${SOURCES})
