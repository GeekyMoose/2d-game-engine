#include "core/RenderEngine.h"

#include "utils/log.h"


void RenderEngine::startup() {
    LOG_TRACE("Startup RenderEngine");
}

void RenderEngine::shutdown() {
    LOG_TRACE("Shutdown RenderEngine");
}

void RenderEngine::update() {
    // TODO: Render all elements
}

RenderSystemSDL* RenderEngine::getRenderSystem() {
    return &this->m_renderSystem;
}
