#pragma once

#include "utils/platform.h"
#include "utils/Singleton.h"
#include "core/Camera.h"
#include "grid/TileMap.h"

#include <stdexcept>

class SDL_Surface;


/**
 * Manager for all components on the scene.
 *
 * \date    Nov 2017
 * \author  Constantin Masson
 */
class SceneManager : private Singleton<SceneManager> {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------
    private:
        friend Singleton<SceneManager>;
    public:
        using Singleton<SceneManager>::getInstance;

    private:
        Camera m_camera;
        TileMap m_tilemap;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        SceneManager() = default;
        ~SceneManager() = default;

    public:
        void startup() override;
        void shutdown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:
        void renderScene(SDL_Surface* dest);
};
