include_directories("${CMAKE_SOURCE_DIR}/include")

file(GLOB_RECURSE srcFiles src/*.cpp)

add_executable(game ${srcFiles})
add_custom_target(run game)

target_link_libraries(game
    ${SDL2_LIBRARY}
    ${SDL2MAIN_LIBRARY}
    ${SDL2_IMAGE_LIBRARY}
    )

# Copy resource file in build
file(COPY resources DESTINATION "${CMAKE_BINARY_DIR}")
