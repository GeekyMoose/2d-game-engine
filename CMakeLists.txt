cmake_minimum_required(VERSION 2.8.2)
project(game)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(src)

