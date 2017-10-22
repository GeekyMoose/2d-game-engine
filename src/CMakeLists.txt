include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB_RECURSE srcFiles *.cpp)

add_executable(game ${srcFiles})
add_custom_target(rungame game)

target_link_libraries(game
    ${SDL2_LIBRARY}
    ${SDL2MAIN_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    )

