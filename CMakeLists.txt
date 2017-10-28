cmake_minimum_required(VERSION 2.8.2)
project(game)

if("${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}")
    message(FATAL_ERROR "in-source build not allowed. Use another directory.")
    exit()
endif()

# Dependencies
include(CMake/Dependencies.cmake)
include(CMake/CompilerFlags.cmake)

add_subdirectory(src)
