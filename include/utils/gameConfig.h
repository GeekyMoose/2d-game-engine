#pragma once

#include "utils/Platform.h"


#define GAME_CONFIG_WINDOW_TITLE "2d game"
#define GAME_CONFIG_DEFAULT_GAME_MAP_PATH "./resources/gamemap/gamemap1.txt"


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

enum GameMapData {
    MAP_SIZE_ROW                = 3,    // Nb area in on map row
    MAP_SIZE_COL                = 2,    // Nb area in on map column
    AREA_NB_TILES_ROW           = 40,   // Nb Tiles in one row
    AREA_NB_TILES_COL           = 40,   // Nb Tiles in one column
    TILE_SIZE_IN_PIXEL          = 20    // Size of a tile in pixel
};
