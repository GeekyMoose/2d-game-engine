#include "core/Engine2D.h"

#include "helper/Logger.h"

#include <chrono>
#include <thread>

Engine2D::Engine2D() : timeManager(TimeManager::getInstance()) {
}

Engine2D::~Engine2D() {
    this->shutDown();
}

void Engine2D::startUp() {
    this->m_isRunning = true;
    this->timeManager.startUp();
}

void Engine2D::shutDown() {
    this->m_isRunning = false;
    this->timeManager.shutDown();
}

void Engine2D::run() {
    while(this->m_isRunning) {
        this->timeManager.updateTimer();
        LOG_DEBUG(this->timeManager.getDeltaTime());

        while(this->timeManager.hasNextFixedFrame()) {
            // TODO Call update
        }
        // TODO Call render
    }
}
