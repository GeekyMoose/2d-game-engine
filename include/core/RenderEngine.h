#pragma once

#include "utils/platform.h"
#include "utils/Singleton.h"
#include "core/RenderSystemSDL.h"


class RenderWindowSDL;


/**
 * Render Engine component.
 * This use a Rendering system with specific implementation (Ex: SDL).
 *
 * \author  Constantin Masson
 * \date    Dec 2017
 */
class RenderEngine : private Singleton<RenderEngine> {
    private:
        friend Singleton<RenderEngine>;
        RenderSystemSDL m_renderSystem;

    public:
        using Singleton<RenderEngine>::getInstance;

    private:
        RenderEngine() = default;
        ~RenderEngine() = default;

    public:
        void startup() override;
        void shutdown() override;

    public:
        void update();

        RenderSystemSDL* getRenderSystem();
};
