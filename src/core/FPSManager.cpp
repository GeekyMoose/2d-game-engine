#include "core/FPSManager.h"

#include "core/TimeManager.h"

#include "helper/Logger.h"

void FPSManager::startUp() {
    this->m_elapsedTimeInSec    = 0;
    this->m_currentFPS          = 0;
    this->m_frameCounter        = 0;
}

void FPSManager::shutDown() {
}

void FPSManager::update() {
    this->m_elapsedTimeInSec += TimeManager::getInstance().getDeltaTime();
    //LOG_DEBUG(this->m_elapsedTimeInSec);
    //LOG_DEBUG(this->m_frameCounter);
    this->m_frameCounter++;

    //If one second since last refresh, update fps data
    if (this->m_elapsedTimeInSec >= 1) {
        // WARNING: Result is not accurate if DeltaTime is high (2sec for instance)
        this->m_elapsedTimeInSec = 0;
        this->m_currentFPS = this->m_frameCounter;
        this->m_frameCounter = 0;
    }
}

int FPSManager::getFPS() const {
    return this->m_currentFPS;
}
