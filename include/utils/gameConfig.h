#pragma once

#include "utils/Platform.h"


#define GAME_CONFIG_WINDOW_TITLE "2d game"


enum {
    WINDOW_DEFAULT_WIDTH        = 640,
    WINDOW_DEFAULT_HEIGHT       = 640
};

enum {
    TIME_FIXED_UPDATE_FPS       = 50    // 50 FPS = 20 milliseconds by Frame
};

enum GameMapData {
    AREA_NB_TILES_ROW           = 40,   // Nb Tiles in one row
    AREA_NB_TILES_COL           = 40,   // Nb Tiles in one column
    TILE_SIZE_IN_PIXEL          = 20    // Size of a tile in pixel
};
