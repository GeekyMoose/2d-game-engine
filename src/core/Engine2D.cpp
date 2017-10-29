#include "core/Engine2D.h"

#include "helper/Logger.h"
#include "core/FPS.h"

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
}

void Engine2D::shutDown() {
    this->m_isRunning = false;
    this->m_timeManager.shutDown();
}

void Engine2D::run() {
    while(this->m_isRunning) {
        this->m_timeManager.updateTimer();
        this->m_fps.update();

        LOG_DEBUG(this->m_fps.getFPS());

        while(this->m_timeManager.hasNextFixedFrame()) {
            // TODO Call update
        }
        // TODO Call render
    }
}
