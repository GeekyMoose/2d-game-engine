#include "core/TimeManager.h"

#include "utils/gameConfig.h"
#include "utils/log.h"


void TimeManager::startup() {
    LOG_TRACE("Startup TimeManager");

    this->m_currentStartTime = std::chrono::steady_clock::now();
    this->m_fixedUpdateTimeInSec = 1.0f / static_cast<float>(TIME_FIXED_UPDATE_FPS);
    this->m_leftOverFixedTime = 0.0f;
}

void TimeManager::shutdown() {
    LOG_TRACE("Shutdown TimeManager");
}

void TimeManager::update() {
    auto oldStartTime = this->m_currentStartTime;
    this->m_currentStartTime = std::chrono::steady_clock::now();

    using std::chrono::duration_cast;
    using std::chrono::seconds;
    using std::chrono::duration;
    this->m_deltaTime = duration_cast<duration<float, seconds::period>>
        (this->m_currentStartTime - oldStartTime).count();

    this->m_leftOverFixedTime += this->m_deltaTime; // Used by fixedDeltaTime
}

void TimeManager::updateFixedFrame() {
    this->m_leftOverFixedTime -= this->m_fixedUpdateTimeInSec;
}

bool TimeManager::hasNextFixedFrame() {
    return this->m_leftOverFixedTime >= this->m_fixedUpdateTimeInSec;
}

float TimeManager::getDeltaTime() const {
    return this->m_deltaTime;
}

float TimeManager::getFixedDeltaTime() const {
    return this->m_fixedUpdateTimeInSec;
}
