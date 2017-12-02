#pragma once

#include "core/Camera.h"
#include "utils/Platform.h"
#include "utils/Singleton.h"
#include "utils/gameConfig.h"
#include "gamemap/GameMap.h"


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
        GameMap m_gameMap;
        Camera  m_camera;


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
};
