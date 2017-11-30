#pragma once

#include "utils/Platform.h"
#include "utils/Singleton.h"
#include "utils/gameConfig.h"
#include "gamemap/GameMap.h"


class GameManager : private Singleton<GameManager> {
    // -------------------------------------------------------------------------
    // Attributes
    // -------------------------------------------------------------------------
    private:
        friend Singleton<GameManager>;
    public:
        using Singleton<GameManager>::getInstance;

    private:
        GameMap m_gameMap;


    // -------------------------------------------------------------------------
    // Init
    // -------------------------------------------------------------------------
    private:
        GameManager() = default;
        ~GameManager() = default;

    public:
        void startup() override;
        void shutdown() override;


    // -------------------------------------------------------------------------
    // Core methods
    // -------------------------------------------------------------------------
    public:
        void render();
};
