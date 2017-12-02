#include "core/RenderSystemSDL.h"
#include "core/RenderWindowSDL.h"

RenderWindowSDL* RenderSystemSDL::newRenderWindow() const {
    return new RenderWindowSDL();
}

void RenderSystemSDL::setRenderWindow(RenderWindowSDL& window) {
    this->m_windowSurface = window.getSurface();
}
