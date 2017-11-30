#include "core/Engine2D.h"

#include "utils/log.h"

#include <chrono>
#include <thread>


Engine2D::Engine2D()
    : m_timeManager(TimeManager::getInstance()),
      m_fpsManager(FPSManager::getInstance()),
      m_inputManager(InputManager::getInstance()),
      m_gameManager(GameManager::getInstance()) {
}

Engine2D::~Engine2D() {
    this->shutdown();
}

void Engine2D::startup() {
    this->m_isRunning = true;
    this->m_timeManager.startup();
    this->m_fpsManager.startup();
    this->m_inputManager.startup();
    this->m_gameManager.startup();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        LOG_ERROR("SDL Error: %s", SDL_GetError());
    }
    this->m_window.initialize();
    this->m_window.show();
}

void Engine2D::shutdown() {
    this->m_isRunning = false;
    this->m_timeManager.shutdown();
    this->m_fpsManager.shutdown();
    this->m_inputManager.shutdown();
    this->m_gameManager.shutdown();
    this->m_window.destroy();
}

// The actual main game loop!
void Engine2D::run() {
    while(this->m_isRunning) {
        this->m_timeManager.update();
        this->m_fpsManager.update();
        this->m_inputManager.update();
        this->m_window.clear();

        LOG_DEBUG("FPS: %d", this->m_fpsManager.getFPS());
        if (this->m_inputManager.isKeyDown("quit")) {
            break;
        }

        while(this->m_timeManager.hasNextFixedFrame()) {
            this->m_timeManager.updateFixedFrame();
            // TODO Call update (FixedUpdate)
        }
        // TODO Call render (Update)

        this->m_window.update();
    }
}
