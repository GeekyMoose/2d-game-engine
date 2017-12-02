#pragma once

#include "utils/Singleton.h"


class RenderWindowSDL;
class RenderSystemSDL;


/**
 * Render Engine component.
 *
 * \author  Constantin Masson
 * \date    Dec 2017
 */
class RenderEngine : private Singleton<RenderEngine> {
    private:
        friend Singleton<RenderEngine>;
        RenderSystemSDL* renderSystem;

    public:
        using Singleton<RenderEngine>::getInstance;

    private:
        RenderEngine() = default;
        ~RenderEngine() = default;

    public:
        RenderWindowSDL* initialize();
        void startup() override;
        void shutdown() override;

    public:
        void update();
};
