#include "core/Engine2D.h"

void Engine2D::startUp() {
    this->isRunning = true;
}

void Engine2D::shutDown() {
    this->isRunning = false;
}

void Engine2D::run() {
    while(this->isRunning) {
        // TODO
    }
}
