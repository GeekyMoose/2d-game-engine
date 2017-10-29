#include "core/Engine2D.h"

#include "helper/Logger.h"

#include <chrono>
#include <thread>


Engine2D::Engine2D()
    : m_timeManager(TimeManager::getInstance()),
      m_fps(FPS::getInstance()),
      m_inputManager(InputManager::getInstance()) {
}

Engine2D::~Engine2D() {
    this->shutDown();
}

void Engine2D::startUp() {
    this->m_isRunning = true;
    this->m_timeManager.startUp();
    this->m_fps.startUp();
    this->m_inputManager.startUp();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        LOG_ERROR(SDL_GetError());
    }
    this->m_window.initialize();
    this->m_window.show();
}

void Engine2D::shutDown() {
    this->m_isRunning = false;
    this->m_timeManager.shutDown();
    this->m_window.destroy();
}

void Engine2D::run() {
    while(this->m_isRunning) {
        this->m_timeManager.updateTimer();
        this->m_fps.update();
        this->m_inputManager.update();

        // TODO TEMP DEBUG
        // LOG_DEBUG(this->m_fps.getFPS());
        if (this->m_inputManager.isKeyDown("quit")) {
            LOG_DEBUG("QUIT PRESSED");
        }
        if (this->m_inputManager.isKeyDown("moveUp")) {
            LOG_DEBUG("moveUp PRESSED");
        }
        if (this->m_inputManager.isKeyDown("moveDown")) {
            LOG_DEBUG("moveDown PRESSED");
        }
        if (this->m_inputManager.isKeyDown("moveRight")) {
            LOG_DEBUG("moveRight PRESSED");
        }
        if (this->m_inputManager.isKeyDown("moveLeft")) {
            LOG_DEBUG("moveLeft PRESSED");
        }

        while(this->m_timeManager.hasNextFixedFrame()) {
            // TODO Call update
        }
        // TODO Call render
    }
}
