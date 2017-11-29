#include "core/Engine2D.h"

#include "utils/log.h"

#include <chrono>
#include <thread>


Engine2D::Engine2D()
    : m_timeManager(TimeManager::getInstance()),
      m_fpsManager(FPSManager::getInstance()),
      m_inputManager(InputManager::getInstance()) {
}

Engine2D::~Engine2D() {
    this->shutDown();
}

void Engine2D::startUp() {
    this->m_isRunning = true;
    this->m_timeManager.startUp();
    this->m_fpsManager.startUp();
    this->m_inputManager.startUp();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        LOG_ERROR("SDL Error: %s", SDL_GetError());
    }
    this->m_window.initialize();
    this->m_window.show();
}

void Engine2D::shutDown() {
    this->m_isRunning = false;
    this->m_timeManager.shutDown();
    this->m_fpsManager.shutDown();
    this->m_inputManager.shutDown();
    this->m_window.destroy();
}

void Engine2D::run() {
    while(this->m_isRunning) {
        this->m_timeManager.update();
        this->m_fpsManager.update();
        this->m_inputManager.update();

        LOG_DEBUG("FPS: %d", this->m_fpsManager.getFPS());
        if (this->m_inputManager.isKeyDown("quit")) {
            break;
        }

        while(this->m_timeManager.hasNextFixedFrame()) {
            this->m_timeManager.updateFixedFrame();
            // TODO Call update
        }
        // TODO Call render
    }
}
