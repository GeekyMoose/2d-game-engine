#include "core/RenderEngine.h"


void RenderEngine::startup() {
}

void RenderEngine::shutdown() {
}

void RenderEngine::update() {
    // TODO: Render all elements
}

RenderSystemSDL* RenderEngine::getRenderSystem() {
    return &this->m_renderSystem;
}
