#pragma once

#include "utils/platform.h"


#define GAME_CONFIG_WINDOW_TITLE "2d game"
#define GAME_CONFIG_DEFAULT_TILEMAP_PATH "./resources/grid/tilemap_test.txt"

#define SPRITE_TILE_NAME        "sprite_tile"
#define TEXTURE_TILE_NAME       "texture_tile"
#define TEXTURE_TILE_PATH       "./resources/textures/tiles_map1.png"


enum {
    TEXTURE_NAME_MAX_SIZE       = 42    // Max length of texture name
};


enum {
    WINDOW_DEFAULT_WIDTH        = 640,  // Default screen width in pixels.
    WINDOW_DEFAULT_HEIGHT       = 640,  // Default screen height in pixels.

    CAMERA_DEFAULT_WIDTH        = 100,  // Camera vision in pixels (x).
    CAMERA_DEFAULT_HEIGHT       = 100   // Camera vision in pixels (y).
};


enum {
    TIME_FIXED_UPDATE_FPS       = 50    // 50 FPS = 20 milliseconds by Frame
};


enum GridConfig {
    TILEMAP_SIZE_ROW            = 40,   // Nb tiles in one map row
    TILEMAP_SIZE_COL            = 40,   // Nb tiles in one map column

    GRID_DEFAULT_X_UNIT_SIZE    = 32,   // Nb pixels in one grid unit (width)
    GRID_DEFAULT_Y_UNIT_SIZE    = 32    // Nb pixels in one grid unit (height)
};
