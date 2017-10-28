cmake_minimum_required(VERSION 2.8.2)
project(game)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
    exit()
endif()

# Dependencies
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

# Compiler Flags
add_definitions(-D _DEBUG)
add_definitions(-g -Wall)
add_definitions(-Winline)

add_subdirectory(src)

