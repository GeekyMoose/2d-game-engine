# 2D tilemap engine
This is a simple 2D engine using SDL2. It is not finished and not functional. I used this project to learn about SDL (special thanks to [sdltutorials.com](http://www.sdltutorials.com/)) as well as some game engine basics.


# Dependencies
- [CMake](https://cmake.org/)
- [SDL2](https://www.libsdl.org/) (must be installed system-wide)
- SDL2_image (must be installed system-wide)


# Build and run (Linux only)
- Requires C++11.
- Compiled and tested with g++ 6.3.0
- Requires "pragma once" support

```bash
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release .. # Debug has an issue, use Release instead
make
make run # Use ESC to exit
```


# Features
- 2D engine
    - TimeManager
    - FPS
    - Sprite Animation
    - 2D map rendering
    - Camera
- GamePlay
    - Player
- Physic
    - Simple 2D collision


# Author
Constantin Masson (geekymoose)
